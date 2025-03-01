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
int sqr(int n){
    int l=0,r=sqrtl(LLONG_MAX);
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid*mid<=n){
            if(mid*mid==n)
                ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
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
        map<int,int>m;
        for(int i=1;i<=n;i++)
            cin>>a[i],m[a[i]]++;
        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            ll D=x*x-4*y;
            ll ans=0;
            if(D>=0&&(sqr(D)!=-1)){
                D=sqr(D);
                // cerr<<D<<"\n";
                int num1=x-D,num2=x+D;
                int ai,bi;
                if(num1%2==0){
                    ai=num1/2;
                    if(y%ai==0){
                        if(y!=ai*ai)
                            ans=m[ai]*m[y/ai];
                        else ans=m[ai]*(m[ai]-1)/2;
                    }
                        
                }
                if(num2%2){
                    ai=num1/2;
                    if(y%ai==0){
                        if(y!=ai*ai)
                            ans+=m[ai]*m[y/ai];
                        else ans+=m[ai]*(m[ai]-1)/2;
                    }
                }
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    // ai^2-ai*x+y=0
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}