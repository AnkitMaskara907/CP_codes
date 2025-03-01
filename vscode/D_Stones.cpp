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
int taka=0,aoki=0;
int recur(vector<int>&dp, vector<int>&a, int j){
    if(dp[j]!=-1)return dp[j];
    if(j==0)return 0;
    dp[j]=0;
    for(int i=1;i<a.size()&&(j-a[i]>=0);i++){
        dp[j]=max(dp[j],j-recur(dp,a,j-a[i]));
    }
    // dp[j][taka]=max amt taka can make when j is the total remaining 
    // dp[j][taka]=max(j-dp[j-a[i]][aoki])
    return dp[j];
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        int k;
        cin>>n>>k;
        // n=11;k=4;
        vector<int>a(k+1);
        for(int i=1;i<=k;i++)cin>>a[i];
        // a={0,1,2,3,6};
        vector<int>dp(n+1,-1);
        recur(dp,a,n);
        cout<<dp[n];
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}