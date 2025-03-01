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
int calc(vector<int>temp){
    int val=1;
    int ind=temp[0];
    for(int i=0;i<5;i++){
        if(temp[i]>temp[i+1])
            val++;
    }
    return val;
}
vector<int> getarr(int u,int v,vector<int>&ind){
    vector<int>temp={ind[u-1],ind[u],ind[u+1],ind[v-1],ind[v],ind[v+1]};
    return temp;
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
        vector<int>a(n+1),ind(n+2);
        for(int i=1;i<=n;i++)
            cin>>a[i],ind[a[i]]=i;
        int rounds=1;
        for(int i=2;i<=n;i++){
            if(ind[i]<ind[i-1])
                rounds++;
        }
        while(m--){
            int u,v;
            cin>>u>>v;
            swap(a[u],a[v]);
            u=a[u],v=a[v];
            if(u>v)swap(u,v);
            int val=calc(getarr(u,v,ind));
            swap(ind[u],ind[v]);
            val-=calc(getarr(u,v,ind));
            rounds-=val;
            cout<<rounds<<"\n";
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}