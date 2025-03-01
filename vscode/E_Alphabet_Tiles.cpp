// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
const int MOD=998244353;
// const ll inf=(1000000000000000000);
typedef pair<ll,ll> pairs;
#define varval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
inline ll mod(ll a){
    return (a-MOD*(a/MOD));
}
ll power(ll a, ll b){ll res=1;a=mod(a);while(b>0){if(b&1){res=mod(res*a);b--;}a=mod(a*a);b>>=1;}
        return res;}
vector<int>fact(1001),invf(1001);
void pre(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000;i++)
        fact[i]=mod(fact[i-1]*i);
    for(int i=1;i<=1000;i++)
        invf[i]=power(fact[i],MOD-2);
    return;
}
ll C(int n,int r){
    return mod(mod(fact[n]*invf[r])*invf[n-r]);
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    pre();
    t=1;
    for(int tc=1;tc<=t;tc++){
        // total letters
        cin>>k;
        vector<int>let(26);
        for(int i=0;i<26;i++)
            cin>>let[i];
        vector<int>dp(k+1);
        dp[0]=1;
        for(int i=0;i<26;i++){
            vector<int>dp2(k+1);
            for(int len=1;len<=k;len++){
                for(int thisC=1;thisC<=let[i];thisC++){
                    if(thisC>len)break;
                    dp2[len]=mod(dp2[len]+dp[len-thisC]*C(len,thisC));
                }
            }
            for(int len=k;len>=1;len--)
                dp[len]=mod(dp[len]+dp2[len]);
        }
        int ans=0;
        for(int i=1;i<=k;i++)
            ans=mod(ans+dp[i]);
        cout<<ans;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}