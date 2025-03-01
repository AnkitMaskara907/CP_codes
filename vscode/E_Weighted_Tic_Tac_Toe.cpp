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
int maxSortedAdjacentDiff(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<2)return 0;
        int mx=arr[0],mn=arr[0];
        
        for(int i=0;i<n;i++)
            mn=min(arr[i],mn),mx=max(arr[i],mx);
        vector<int>mxBucket(n,-1),mnBucket(n,-1);
        double delta=(mx-mn)*1.0/(1.0*(n-1));
        // cout<<delta<<"\n";
        for(int i=0;i<n;i++){
            int d=ceil((double)(arr[i]-mn)*1.0/delta);
            // cout<<d<<"\n";
            mxBucket[d]=max(mxBucket[d],arr[i]);
            if(mnBucket[d]==-1)
                mnBucket[d]=arr[i];
            else mnBucket[d]=min(mnBucket[d],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,mxBucket[i]-mnBucket[i]);
        }
        for(int i=0;i<n;){
            int j=i+1;
            while(j<n&&mnBucket[j]==-1)
                j++;
            ans=max(ans,mnBucket[j]-mxBucket[i]);
            i=j;
        }
        return ans;
    }
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<maxSortedAdjacentDiff(arr);
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;

}