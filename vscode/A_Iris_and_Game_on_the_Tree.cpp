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
vector<int>vis,score;
vector<vector<int>>a;
string colors;
// turn=1 for 10
void dfs(int node,int turn){
    vis[node]=1;
    for(auto child:a[node]){
        score[child]=score[node];
        if(!vis[child]){
            if(colors[child-1]=='?'){
                colors[child-1]=char('0'+turn);
                turn^=1;
            }
            if(colors[node]=='1'&&colors[child]=='0')
                score[child]++;
            else if(colors[node]!=colors[child])
                score[child]--;
            dfs(child,turn);
        }
    }
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int nodes;
        cin>>nodes;
        vis.resize(nodes+1);
        score.resize(nodes+1);
        a.resize(nodes+1,vector<int>());
        for(int i=1;i<nodes;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cin>>colors;
        if(colors[0]=='?')
            colors[0]='1',dfs(1,0);
        else dfs(1,1);
        int ans=0;
        for(int i=2;i<=nodes;i++){
            if((a[i].size()==1)&&score[i])
                ans++;
            // cerr<<ans<<"\n";
        }
        cout<<ans<<"\n";
        cerr<<colors<<"\n";
        a.clear();
        vis.clear();
        score.clear();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}