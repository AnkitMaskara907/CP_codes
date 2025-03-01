#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <numa.h>
#include <sched.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_SIZE (1024 * 1024 * 100) // 100 MB
#define ITERATIONS 1000

// Function to bind a thread to a specific core
void bind_to_core(int core) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core, &cpuset);

    if (sched_setaffinity(0, sizeof(cpu_set_t), &cpuset) != 0) {
        perror("sched_setaffinity failed");
        exit(EXIT_FAILURE);
    }
}

// Function to measure latency by repeatedly accessing memory
uint64_t measure_latency(int *array, size_t size) {
    uint64_t sum = 0;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (size_t i = 0; i < ITERATIONS; i++) {
        for (size_t j = 0; j < size; j += 64 / sizeof(int)) { // Stride access to simulate latency
            sum += array[j];
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    uint64_t start_ns = start.tv_sec * 1e9 + start.tv_nsec;
    uint64_t end_ns = end.tv_sec * 1e9 + end.tv_nsec;

    return (end_ns - start_ns) / ITERATIONS; // Average latency per iteration
}

int main() {
    // Check if NUMA is available
    if (numa_available() == -1) {
        fprintf(stderr, "NUMA is not available on this system.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory on NUMA node 1
    int *array = (int *)numa_alloc_onnode(ARRAY_SIZE * sizeof(int), 1);
    if (!array) {
        perror("numa_alloc_onnode failed");
        return EXIT_FAILURE;
    }

    // Initialize the memory
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Measure latency when pinned to a core on NUMA node 1 (local access)
    printf("Measuring latency with thread on NUMA node 1 (local access):\n");
    bind_to_core(8); // Assume core 8 is on NUMA node 1
    uint64_t local_latency = measure_latency(array, ARRAY_SIZE);
    printf("Local access latency: %lu ns\n", local_latency);

    // Measure latency when pinned to a core on NUMA node 0 (remote access)
    printf("Measuring latency with thread on NUMA node 0 (remote access):\n");
    bind_to_core(0); // Assume core 0 is on NUMA node 0
    uint64_t remote_latency = measure_latency(array, ARRAY_SIZE);
    printf("Remote access latency: %lu ns\n", remote_latency);

    // Free allocated memory
    numa_free(array, ARRAY_SIZE * sizeof(int));

    return 0;
}
