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
vector<vector<int>>a;
vector<int>vis;
int cycle(int node,int color){// true means cyvle nahi hai
    // cerr<<"node="<<node<<"\n";
    vis[node]=-1;
    int rtr=-1;
    for(int child:a[node]){
        if(vis[child]==-1){
            rtr=child;
            break;
        }
        else if(vis[child]==0)
            rtr=max(rtr,cycle(child,color));
    }
    vis[node]=color;
    return rtr;
}

int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        a.resize(n+1);
        vis.resize(n+1);
        for(int i=1;i<=n;i++){
            int u;
            cin>>u;
            a[i].pb(u);
        }
        int checkFor=-1,color=-1;
        for(int i=1;i<=n;i++){
            int poss=-1;
            if(vis[i]==0){
                poss=cycle(i,i);
                if(poss!=-1){
                    checkFor=poss;
                    color=i;
                    break;
                }
            }
        }
        // cerr<<checkFor;
        // for(auto x:vis)
            // cerr<<x<<" ";
        vector<int>ans;
        int node=checkFor;
        ans.push_back(node);
        do{
            // cerr<<node<<'\n';
            for(auto child:a[node]){
                if(vis[child]==color){
                    ans.push_back(child);
                    node=child;
                    break;
                }
            }
        }while(node!=checkFor);

        ans.pop_back();
        cout<<ans.size()<<"\n";
        for(auto x:ans)
            cout<<x<<" ";
        a.clear();
        vis.clear();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}