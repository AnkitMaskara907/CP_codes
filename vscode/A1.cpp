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
int r,c;
vector<vector<int>>a,vis;
vector<int>par,sz;
int val(int i,int j){
    return (i*(r-1)+j);
}
int get(int node){
    if(par[node]!=node)
        return get(par[node]);
    return node;
}
void merge(int a,int b){
    a=get(a);
    b=get(b);
    if(sz[a]>sz[b])
        par[b]=a,sz[a]+=sz[b],sz[b]=0;
    else par[a]=b,sz[b]+=sz[a],sz[a]=0;
    return;
}

int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        // int r,c;
        cin>>r>>c;
        a.resize(r+1,vector<int>(c+2,1));
        vis.resize(r+1,vector<int>(c+2));
        par.resize((r+1)*(c+2));
        sz.resize((r+1)*(c+2),1);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                par[i*(r-1)+j]=i*(r-1)+j;
                char ch;
                cin>>ch;
                if(ch=='W')
                    a[i][j]=0;
                else if(ch=='.')
                    a[i][j]=-1;
            }
        }
        int mx=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(a[i][j]!=-1){
                    if(a[i][j-1]==a[i][j])
                        merge(val(i,j),val(i,j-1));
                    if(a[i-1][j]==a[i][j])
                        merge(val(i,j),val(i-1,j));
                    if(a[i][j+1]==a[i][j])
                        merge(val(i,j),val(i,j+1));
                    if(a[i+1][j]==a[i][j])
                        merge(val(i,j),val(i+1,j));
                }
                else if(a[i][j]==1){
                    if()
                }
            }
        }
        if(mx){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        vis.clear();
        a.clear();
        par.clear();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}