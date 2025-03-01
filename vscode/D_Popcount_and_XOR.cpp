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
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        int a,b,c;
        cin>>a>>b>>c;
        int pc=0,po=1;
        for(int i=0;i<60;i++){
            if(po&c)pc++;
            po*=2;
        }
        int diffA=(pc+a-b)/2,diffB=0,x=0,y=0;
        diffB=pc-diffA;
        bool poss=true;
        // cerr<<diffA<<" "<<diffB<<"\n";
        int same=a-diffA;
        if(diffA<0||diffB<0)
            poss=false;
        if(same<0)poss=false;
        po=1;
        for(int i=0;i<60;i++){
            if(c&po){
                if(diffA>0)
                    x=(x|po),diffA--;
                else
                    y=(y|po),diffB--;
            }
            else if(same){
                x=(x|po);y=(y|po);same--;
            }
            po*=2;
        }
        if(poss&&((x^y)==c)&&(__builtin_popcountll(x)==a)&&(__builtin_popcountll(y)==b))
            cout<<x<<" "<<y<<"\n";
        else cout<<-1<<"\n";
        // cerr<<long(x^y);
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}