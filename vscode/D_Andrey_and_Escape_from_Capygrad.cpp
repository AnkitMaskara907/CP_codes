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
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<pair<int,int>>ranges(n+1);
        for(int i=1;i<=n;i++){
            int l,r,a,b;
            cin>>l>>r>>a>>b;
            ranges[i]={l,b};
        }
        int m;
        cin>>m;
        vector<int>X(m+1);
        for(int i=1;i<=m;i++)
            cin>>X[i];
        sort(all(ranges));
        vector<pair<int,int>>franges;
        franges.push_back(ranges[1]);
        for(int i=2;i<=n;i++){
            if(franges.back().S>=ranges[i].F)
                franges.back().S=max(franges.back().S,ranges[i].S);
            else 
                franges.push_back(ranges[i]);
        }
        n=franges.size();
        for(int i=1;i<=m;i++){
            int l=0,r=n-1,ans=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(franges[mid].F<=X[i])
                    ans=mid,l=mid+1;
                else r=mid-1;
            }
            if(ans==-1)
                cout<<X[i]<<" ";
            else if(franges[ans].F<=X[i]&&franges[ans].S>=X[i])
                cout<<franges[ans].S<<" ";
            else cout<<X[i]<<" ";
        }
        cout<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}