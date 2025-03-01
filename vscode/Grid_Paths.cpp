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

int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<vector<int>>a(n+1,vector<int>(n+1)),dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                char ch;
                cin>>ch;
                a[i][j]=(ch=='.')?1:0;
            }
        }
        dp[1][1]=a[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==0)continue;
                if(j!=1)
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
                if(i!=1)
                    dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
        }
        cout<<dp[n][n];
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}