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
        vector<int>a(n+1),p(n+1),elements(n+2);
        for(int i=1;i<=n;i++)cin>>a[i];
        if(a[1]==1)p[1]=0;
        else p[1]=a[1]*-1;
        // 1 2 3 
        // -1 -2 -3
        // 0 2 3 5
        // mex(.. p[i]) = mex(p[i-1])+something -a[i]
        // p[i]+a[i]=mex(p[i-1])+something
        // a[i]-mex(p[i-1]=something-p[i]
        // a[i]-mex(p[i-1])+p[i]>=0
        set<int>s;
        for(int i=0;i<n;i++)
            s.insert(i);
        s.erase(p[1]);
        elements[p[1]]=1;
        int mex=0;
        while(elements[mex])mex++;
        for(int i=2;i<=n;i++){
            int val=a[i]-mex;
            auto it=s.lower_bound(-val);
            p[i]=*it;
            elements[*it]++;
            while(elements[mex])mex++;
            s.erase(it);
        }
        for(int i=1;i<=n;i++)cout<<p[i]<<" ";
        cout<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}