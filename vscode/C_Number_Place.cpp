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
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        vector<vector<int>>mat(10,vector<int>(10));
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++)
                cin>>mat[i][j];
        }
        map<int,int>m;
        bool poss=true;
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                m[mat[i][j]]++;
                if(m[mat[i][j]]!=i)poss=false;
            }
        }
        m.clear();
        for(int j=1;j<=9;j++){
            for(int i=1;i<=9;i++){
                m[mat[i][j]]++;
                if(m[mat[i][j]]!=j)poss=false;
            }
        }
        // cerr<<poss;
        m.clear();
        for(int st=1;st<=9;st+=3){
            for(int db=1;db<=9;db+=3){
                for(int i=db;i<db+3;i++){
                    for(int j=st;j<st+3;j++){
                        m[mat[i][j]]++;
                        if(m[mat[i][j]]!=1)poss=false;
                    }
                }
                m.clear();
            }
        }
        if(poss)cout<<"Yes";
        else cout<<"No";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}