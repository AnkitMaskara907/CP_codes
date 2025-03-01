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
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
bool isValid(int i,int j,int n){
    return i>=0&&j>=0&&i<n&&j<n;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        // free cells 
        int d;
        cin>>n>>d;
        queue<pair<int,int>>q;
        vector<vector<char>>mat(n,vector<char>(n));
        vector<vector<int>>man(n,vector<int>(n,n*10));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='#'){
                    q.push({i,j});
                    man[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int i=curr.first,j=curr.second;
            for(int ind=0;ind<4;ind++){
                int x=dx[ind],y=dy[ind];
                    if(isValid(i+x,j+y,n)){
                        if(man[i+x][y+j]==n*10){
                            q.push({i+x,j+y});
                            man[i+x][j+y]=man[i][j]+1;
                            // cerr<<i+x<<" "<<j+y<<" "<<man[i+x][j+y]<<"\n";
                        }
                    }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<(man[i][j]<=d?'x':'.');
            cout<<"\n";
        }

    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}