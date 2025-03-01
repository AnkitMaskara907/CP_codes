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
        cin>>k;
        vector<vector<int>>dp(10,vector<int>(11)),count(10,vector<int>(11));
        for(int i=0;i<10;i++)
            dp[i][1]=1;
        for(int fv=2;fv<=10;fv++){
            for(int dig=0;dig<10;dig++){
                if(dig-1>=0)
                    dp[dig][fv]+=dp[dig-1][fv-1];
                dp[dig][fv]+=dp[dig][fv-1];
                if(dig+1<=9)
                    dp[dig][fv]+=dp[dig+1][fv-1];
            }
        }
        for(int fv=1;fv<=10;fv++){
            count[1][fv]=count[9][fv-1];
            for(int dig=0;dig<10;dig++){
                if(dig>=2)
                    count[dig][fv]=count[dig-1][fv];
                if(dig-1>=0)
                    count[dig][fv]+=dp[dig-1][fv-1];
                count[dig][fv]+=dp[dig][fv-1];
                if(dig+1<=9)
                    count[dig][fv]+=dp[dig+1][fv-1];
                
            }
        }
        k++;
        bool found=false;
        int num=0;
        int currfv=10,currdig=9;
        while(count[1][currfv]>k){
            currfv--;   
        }
        while(count[currdig][currfv]>k)
            currdig--;
        cout<<count[9][10]-1;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}