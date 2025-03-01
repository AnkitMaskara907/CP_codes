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
vector<int>col,vis;
vector<vector<int>>a;
bool dfs(int node,int color){
    bool poss=false;
    col[node]=color;
    vis[node]=1;
    for(auto child:a[node]){
        if(!vis[child])
            poss=poss||(dfs(child,color^1));
        else if(vis[child]&&(col[child]==color))
            poss=true;
    }
    return poss;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        int m;
        cin>>n>>m;
        a.resize(n+1);
        col.resize(n+1);
        vis.resize(n+1);
        while(m--){
            int u,v;
            cin>>u>>v;
            a[u].pb(v);
            a[v].push_back(u);
        }
        for(int i=1;i<=n;i++)cin>>k;
        bool poss=false;
        poss=dfs(1,1);        
        if(poss)
            cout<<"Yes";
        else cout<<"No\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}