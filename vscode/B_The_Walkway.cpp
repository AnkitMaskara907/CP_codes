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
    // t=100;
    for(int tc=1;tc<=t;tc++){
        int m,d;
        cin>>n>>m>>d;
        vector<int>s(m+1);
        for(int i=1;i<=m;i++){
            cin>>s[i];
        }
        s[0]=1;
        vector<int>suff(m+1);
        suff[m]=1+(n-s[m])/d;
        for(int i=m-1;i>=0;i--){
            suff[i]=suff[i+1]+1;
            suff[i]+=(s[i+1]-s[i]-1)/d;
        }
        int total=suff[0];
        if(s[1]==1){total--;suff[0]=suff[1]=total;}
        int mincookies=MOD,cookies=1;
        int cnt=0l;
        for(int i=1;i<=m;i++){
            if(i!=m)
                cookies=(s[i+1]-1-s[i-1])/d+suff[i+1]+1+(total-suff[i-1]);
            
            else 
                cookies=(n-s[i-1])/d+1+(total-suff[i-1]);
            if(cookies<mincookies)cnt=1;
            else if(cookies==mincookies)cnt++;
            mincookies=min(mincookies,cookies);
        }
        
        cout<<mincookies<<" "<<cnt<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}