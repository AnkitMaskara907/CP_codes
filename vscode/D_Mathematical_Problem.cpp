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
    for(int i=10;i<=100;i++){
        if(i*i>=1000)break;
        cout<<i*i<<"\n";
    }
    // cin>>t;
    t=0;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        try{
            for(int i=0;i<n/2;i++){
                cout<<1<<string(n-1-(n/2+i+1),'0')<<6<<string(n/2-i-1,'0')<<9<<string(2*i,'0')<<"\n";
                cout<<9<<string(n-1-(n/2+i+1),'0')<<6<<string(n/2-i-1,'0')<<1<<string(2*i,'0')<<"\n";
            }
            cout<<196<<string(n-3,'0')<<"\n";
        }
        catch(exception e){
            cout<<e.what()<<"\n";
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}