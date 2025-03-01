// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
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
bool cmp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
    if(a.F.F<b.F.F)
        return true;
    if(a.F.F==b.F.F)
        return (a.F.S>b.F.S);
    return false;
}
bool cmp2(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
    if(a.F.S<b.F.S)
        return true;
    if(a.F.S==b.F.S)
        return (a.F.F>b.F.F);
    return false;
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
        vector<pair<pair<int,int>,int>>a(n+1);
        vector<int>enclosed(n+1),enclosing(n+1);
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            a[i]={{x,y},i};
        }
        sort(a.begin()+1,a.end(),cmp);
        ordered_set os;
        // for(int i=1;i<=n;i++)
        //     cout<<a[i].F.F<<" "<<a[i].F.S<<"\n";
        long long ans=0;
        for(int i=1;i<=n;i++){
            int x=a[i].F.F,y=a[i].F.S,ind=a[i].S;
            int it=os.order_of_key(y);
            enclosed[ind]=i-1-it;
            ans+=i-1-it;
            // cout<<ans<<"\n";
            os.insert(y);
        }
        os.clear();
        sort(a.begin()+1,a.end(),cmp2);
        for(int i=1;i<=n;i++){
            int x=a[i].F.F,y=a[i].F.S,ind=a[i].S;
            int it=os.order_of_key(x);
            enclosing[ind]=i-1-it;
            ans+=i-1-it;
            // cout<<ans<<"\n";
            os.insert(x);
        }
        for(int i=1;i<=n;i++)
            cout<<enclosing[i]<<" ";
        cout<<"\n";
        for(int i=1;i<=n;i++)
            cout<<enclosed[i]<<" ";
        // cout<<ans<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}