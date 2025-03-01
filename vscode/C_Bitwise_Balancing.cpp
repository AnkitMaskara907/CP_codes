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
        int b,c,d,a=0;
        cin>>b>>c>>d;
        int mx=(1ll<<60);
        bool poss=true;
        for(int bitVal=mx;bitVal>0;bitVal/=2){
            if(d&bitVal){
                if((!(b&bitVal))&(!(c&bitVal)))
                    a+=bitVal;
            }
            else{
                if((c&bitVal))
                    a+=bitVal;
            }
        }
        // cerr<<a<<"\n";
        if(((a|b)-(a&c))==d)
            cout<<a<<"\n";
        else cout<<-1<<"\n";
        // cerr<<diff<<"\n";
// a b c d
// 1 0 0 1
// 1 1 0 1
// 0 1 0 1
// 0 1 1 1
// 1 0 1 0
// 1 1 1 0
// 0 0 0 0
// 0 0 1 0


    }
    // 
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}