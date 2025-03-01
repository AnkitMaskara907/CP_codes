import com.sun.jna.*;
import com.sun.jna.ptr.PointerByReference;

import java.nio.ByteBuffer;
import java.util.Arrays;

public class NumaLatencyTest {

    // Define the libc interface for JNA
    public interface LibC extends Library {
        LibC INSTANCE = Native.load("c", LibC.class);

        int sched_setaffinity(int pid, int cpusetsize, Pointer cpuset);

        int clock_gettime(int clk_id, Timespec tp);

        int getpid();
    }

    // Define Timespec structure
    public static class Timespec extends Structure {
        public long tv_sec;  // seconds
        public long tv_nsec; // nanoseconds

        @Override
        protected List<String> getFieldOrder() {
            return Arrays.asList("tv_sec", "tv_nsec");
        }
    }

    private static final int CLOCK_MONOTONIC = 1;
    private static final int ARRAY_SIZE = 1024 * 1024 * 100; // 100 MB
    private static final int ITERATIONS = 1000;

    // Function to bind a thread to a specific core
    public static void bindToCore(int core) {
        int pid = LibC.INSTANCE.getpid();
        int cpuSetSize = Native.getNativeSize(Long.TYPE) * 8; // Assume 64-bit system
        Pointer cpuSet = new Memory(cpuSetSize);
        cpuSet.clear(cpuSetSize);
        cpuSet.setByte(core / 8, (byte) (1 << (core % 8)));

        if (LibC.INSTANCE.sched_setaffinity(pid, cpuSetSize, cpuSet) != 0) {
            throw new RuntimeException("Failed to set CPU affinity for core: " + core);
        }
    }

    // Function to measure latency by repeatedly accessing memory
    public static long measureLatency(int[] array) {
        long sum = 0;
        Timespec start = new Timespec();
        Timespec end = new Timespec();

        LibC.INSTANCE.clock_gettime(CLOCK_MONOTONIC, start);
        for (int i = 0; i < ITERATIONS; i++) {
            for (int j = 0; j < array.length; j += 16) { // Stride access to simulate latency
                sum += array[j];
            }
        }
        LibC.INSTANCE.clock_gettime(CLOCK_MONOTONIC, end);

        long startNs = start.tv_sec * 1_000_000_000L + start.tv_nsec;
        long endNs = end.tv_sec * 1_000_000_000L + end.tv_nsec;

        return (endNs - startNs) / ITERATIONS;
    }

    public static void main(String[] args) {
        // Allocate memory (simulating NUMA allocation with a large array)
        int[] array = new int[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = i;
        }

        // Measure latency when pinned to a core (local access)
        System.out.println("Measuring latency with thread pinned to core 0 (simulating local access):");
        bindToCore(0);
        long localLatency = measureLatency(array);
        System.out.println("Local access latency: " + localLatency + " ns");

        // Measure latency when pinned to another core (remote access simulation)
        System.out.println("Measuring latency with thread pinned to core 1 (simulating remote access):");
        bindToCore(1);
        long remoteLatency = measureLatency(array);
        System.out.println("Remote access latency: " + remoteLatency + " ns");
    }
}
