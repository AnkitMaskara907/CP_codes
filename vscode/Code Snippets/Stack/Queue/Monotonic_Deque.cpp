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
ll power(ll a, ll b){ll res=1;a=mod(a);while(b>0){if(b&1){res=mod(res*a);b--;}a=mod(a*a);b>>=1;}
        return res;}
int getAns(vector<int>&arr,int d){
    deque<int>DecElements;
    int n=arr.size();
    int ans=INT_MAX;
    for(int i=0;i<d;i++){
        int currElement=arr[i];
        // largest to smallest
        while(!DecElements.empty()&&arr[DecElements.back()]<=currElement){
            DecElements.pop_back();
        }
        DecElements.push_back(i);
    }
    ans= min(ans,arr[DecElements.front()]);
    for(int i=d;i<n;i++){
        int currElement= arr[i];
        if(DecElements.front()<=(i-d))
            DecElements.pop_front();
        while(!DecElements.empty()&&arr[DecElements.back()]<=currElement)
            DecElements.pop_back();
        DecElements.push_back(i);
        ans=min(ans,arr[DecElements.front()]);
    }
    return ans;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        
        
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}