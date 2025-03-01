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
int gcd(int a,int b){
    if(a==0)return b;
    return gcd(b%a,a);
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<int>a(n+1);
        int sum=0,G,mx=-MOD;
        map<int,int>m;
        for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),m[a[i]]++;
        // N-a[1]=x*k1
        // N-a[2]=x*k2
        if(n==1){
            cout<<1<<"\n";continue;
        }
        G=llabs(a[1]-a[2]);
        for(int i=3;i<=n;i++)
            G=gcd(G,llabs(a[i]-a[i-1]));
        int ans=0,ele=mx;
        while(m[ele-G])
            ele-=G;
        a[0]=ele-G;
        for(int i=0;i<=n;i++)
            ans+=llabs(mx-a[i])/G;
        cout<<ans<<"\n";
        // cerr<<G<<" "<<ele<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}