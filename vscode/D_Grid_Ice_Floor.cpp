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
// using namespace chrono;q
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
int n,m;
vector<vector<char>>a;
vector<vector<vector<int>>>col;
bool Valid(int dir,int i,int j){
    int d2=-1;
    if(dir==1||dir==4)d2=1;
    else d2=2;
    if(dir==1)
    return (col[i-1][j][dir]==0);
    if(dir==2)
        return (col[i][j-1][dir]==0);
    if(dir==3)
        return (col[i][j+1][dir]==0);
    return (col[i+1][j][dir]==0);
    
}
void dfs(int dir,int i,int j){
    // cerr<<dir<<" "<<i<<" "<<j<<"\n";
    int d2=-1;
    if(dir==1||dir==4)d2=1;
    else d2=2;
    if(col[i][j][d2]==-1||col[i][j][d2]==1)
        return;
    col[i][j][d2]=1;
    if(Valid(dir,i,j)){
        if(dir==1)
            dfs(dir,i-1,j);
        else if(dir==2)
            dfs(dir,i,j-1);
        else if(dir==3)
            dfs(dir,i,j+1);
        else dfs(dir,i+1,j);
    }
    // else if(col[i][j]==4)
    //     return;
    else {
        if(dir!=1)
            dfs(1,i-1,j);
        if(dir!=2)
            dfs(2,i,j-1);
        if(dir!=3)
            dfs(3,i,j+1);
        if(dir!=4)
            dfs(4,i+1,j);
    }
    return;
        
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        // int m;
        cin>>n>>m;
        a.resize(n+1,vector<char>(m+1));
        col.resize(n+1,vector<vector<int>>(m+1,vector<int>(5)));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='#')
                    col[i][j][1]=col[i][j][2]=col[i][j][3]=col[i][j][4]=-1;
                else col[i][j][1]=col[i][j][2]=col[i][j][3]=col[i][j][4]=0;
            }
        }
        dfs(3,2,2);
        
        dfs(4,2,2);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(col[i][j][1]>0||col[i][j][2]>0||col[i][j][3]>0||col[i][j][4]>0)ans++;
            }
        }
        cout<<ans<<"\n";
        
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}