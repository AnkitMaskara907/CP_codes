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
const int MOD=(998244353);
// const ll inf=(1000000000000000000);
typedef pair<ll,ll> pairs;
#define varval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
inline ll mod(ll a){
    return (a-MOD*(a/MOD));
}
ll power(ll a, ll b){ll res=1;a=mod(a);while(b>0){if(b&1){res=mod(res*a);b--;}a=mod(a*a);b>>=1;}
        return res;}
vector<int>par,sz;
int ans=1,s;
int get(int node){
    if(par[node]==node)
        return node;
    return par[node]=get(par[node]);
}
void merge(int a,int b,int w){
    a=get(a);
    b=get(b);
    int edges=sz[a]*sz[b]-1;
    if(edges>0)
        ans=mod(ans*mod(power(s-w+1,edges)));
    if(sz[a]>=sz[b]){
        par[b]=a;sz[a]+=sz[b];sz[b]=0;
    }
    else{ 
        par[a]=b;sz[b]+=sz[a];sz[a]=0;
    }
    return;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        // int s;
        cin>>n>>s;
        vector<pair<int,pair<int,int>>>a(n);
        par.resize(n+1);
        sz.resize(n+1,1);
        int mxedge=0;
        for(int i=1;i<n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            a[i]={w,{u,v}};
        }
        iota(all(par),0ll);
        sort(all(a));
        for(int i=1;a[i].F<s&&(i<n);i++){
            int u=a[i].S.F,v=a[i].S.S,w=a[i].F;
            merge(u,v,w);
        }
        cout<<ans<<"\n";
        par.clear();sz.clear();ans=1;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}