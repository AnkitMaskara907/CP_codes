// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
// order_of_key(k), find_by_order(k)
// using namespace chrono;
#define F first
#define S second
#define lld long double
#define vc vector<ll>
#define pb push_back
#define all(a) a.begin(),a.end()
const int MOD=(1e9 +7);
// const ll inf=(1000000000000000000);
typedef pair<ll,ll> pairs;
#define varval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
inline ll mod(ll a){
    return (a-MOD*(a/MOD));
}


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LFUCache* cache=new LFUCache(3);
    cache->put(1,1);
    cache->put(2,2);
    cache->put(3,3);
    cache->put(4,4);
    cout<<cache->get(4)<<"\n";
    cout<<cache->get(3)<<"\n";
    cout<<cache->get(2)<<"\n";
    cout<<cache->get(1)<<"\n";
    cache->put(5,5);
    cout<<cache->get(1)<<"\n";
    cout<<cache->get(2)<<"\n";
    cout<<cache->get(3)<<"\n";
    cache->get(4);cache->get(5);
    return 0;
}