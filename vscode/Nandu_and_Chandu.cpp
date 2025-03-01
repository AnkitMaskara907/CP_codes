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
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        // for every index, we have an option to make it greater than the previous elements
        // keep a track of the max element used till now and accordingly check what the next element would be
        int n,mx,peaks;
        cin>>n>>mx>>peaks;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(peaks+1,vector<int>(mx+1)));

        for(int i=1;i<=mx;i++)
            dp[1][0][i]=1+dp[1][0][i-1];
        
        for(int i=2;i<=n;i++){
            for(int peak=0;peak<=peaks;peak++){
                for(int m=1;m<=mx;m++){

                    dp[i][peak][m]=dp[i][peak][m-1];

                    dp[i][peak][m]=(dp[i-1][peak][m]-dp[i-1][peak][m-1])*m+(peak?dp[i-1][peak-1][m-1]:0);
    
                }
            }
        }
        cout<<dp[n][peaks][mx]<<"\n";
        // int ans=0;
        // for(int i=1;i<=mx;i++){
        //     // cerr<<dp[n][peaks][i]<<"\n";
        //     ans+=dp[n][peaks][i];
        // }
        // for(int i=0;i<=peaks;i++)
        //     cerr<<dp[n][i][mx]<<"\n";
        // number of arrays to form till index i with peak peaks and max element as m 
        // dp[i][peak][m]= dp[i-1][peak][m]*m+dp[i-1][peak-1][m-1]
        
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
    // intern[i]={r[k1],r[k2],r[k3],r[k4]}
    // intern[i]={}
    // room[i]={int1,int2,int3,int4}
    // every room i'll need to store the interns with priority for them
    // sort them on the basis of number of rooms they want to prioritize
    // 
        return 0;
}