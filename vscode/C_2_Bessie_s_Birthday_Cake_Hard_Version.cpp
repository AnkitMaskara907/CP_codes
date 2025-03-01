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
        int x,y;
        cin>>n>>x>>y;
        vector<int>a(x+1);
        // a[0]=2*MOD;
        // cerr<<a[0]<<"\n";
        for(int i=1;i<=x;i++)
            cin>>a[i];
        sort(all(a));
        int ans=x+y-2;
        int verticesLeft=n-(x+y);
        // gap-2 /2
        vector<int>gap;
        vector<int>odd,even;
        for(int i=2;i<=x;i++)
            gap.push_back(a[i]-a[i-1]-1);
        
        gap.push_back(n-a[x]+a[1]-1);
        sort(all(gap),greater<int>());
        for(auto g:gap){
            if(!g)break;
            int mn=min(verticesLeft,(g+1)/2);
            verticesLeft-=mn;
            ans+=mn;
            if(g%2)odd.push_back(g);
            else even.push_back(g);
            // cerr<<ans<<"\n";
        }
        for(auto o:even){
            int mn=min(verticesLeft,o/2);
            verticesLeft-=mn;
            ans-=mn;
        }

        if(verticesLeft)
            for(auto o:odd){
                if(!verticesLeft)break;
                int mn=min(verticesLeft,o/2);
                verticesLeft-=mn;
                ans-=mn+1;
            }
        cout<<ans<<"\n";
    }   
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}