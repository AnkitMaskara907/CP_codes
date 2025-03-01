// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long double
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
    cout<<setprecision(9)<<fixed;
    cerr<<setprecision(9)<<fixed;
    cin>>t;
    for(long tc=1;tc<=t;tc++){
        cin>>n;
        vector<pair<int,int>>window(n+1);
        for(int i=1;i<=n;i++)
            cin>>window[i].F>>window[i].S;
        int delta=1e-8,l=0,r=10000000,ans=-1;
        while(r-l>=delta){
            int speed=(l+r)/2;
            bool poss=true,less=false,more=false;
            for(int i=1;i<=n;i++){
                int time=i/speed;
                if((time<window[i].F)||(time>window[i].S)){
                    poss=false;
                    if(time<window[i].F)
                        less=true;
                    else more=true;
                    break;
                }
            }
            if(poss){
                ans=speed;
                r=speed-delta;
            }
            else{
                if(more)l=speed+delta;
                else r=speed-delta;
            }
        }
        cout << "Case #"<<tc<<": "<< ans<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}