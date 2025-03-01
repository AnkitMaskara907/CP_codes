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

int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        int q;
        cin>>n>>q;
        vector<int>a(q+1),ss(q+1),ans(n+1);
        set<int>s;
        vector<vector<int>>occ(n+1);
        for(int i=1;i<=q;i++){
            cin>>a[i];
            auto it=s.find(a[i]);
            if(it==s.end())
                s.insert(a[i]),ss[i]=ss[i-1]+1,occ[a[i]].push_back(i);
            else {
                occ[a[i]].push_back(i);
                s.erase(it);
                ss[i]=ss[i-1]-1;
            }
        }
        for(int i=1;i<=q;i++){
            ss[i]+=ss[i-1];
        }
        for(int i=1;i<=n;i++){
            int len=occ[i].size();
            if(len%2){
                occ[i].push_back(q+1);
                len++;
            }
            for(int k=1;k<len;k+=2){
                ans[i]+=ss[occ[i][k]-1]-ss[occ[i][k-1]-1];
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}