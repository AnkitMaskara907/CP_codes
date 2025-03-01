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
int getMex(int m,int e,int x){
    set<int>s={m,e,x};
    for(int i=0;i<=3;i++){
        if(s.find(i)==s.end())
            return i;
    }
    return 0;
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
        vector<int>a(n+1);
        int M[n][3],E[n][3],X[n][3];
        memset(M,0,sizeof(M));
        memset(E,0,sizeof(M));
        memset(X,0,sizeof(M));
        for(int i=0;i<n;i++)
            cin>>a[i];
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='M')
                M[i][a[i]]=1;
            else if(s[i]=='E')
                E[i][a[i]]=1;
            else X[i][a[i]]=1;
            if(i!=0){
                for(int j=0;j<3;j++){
                    M[i][j]+=M[i-1][j];
                    E[i][j]+=E[i-1][j];
                    X[i][j]+=X[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int m=0;m<3;m++){
                for(int e=0;e<3;e++){
                    for(int x=0;x<3;x++){
                        int mex=getMex(m,e,x);
                        ans+=mex*(M[i-1][m]*(E[i][e]-E[i-1][e])*(X[n-1][x]-X[i][x]));
                    }
                }
            }
        }
        cout<<ans;

    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}