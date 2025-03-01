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
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int m;
        cin>>n>>m>>k;
        vector<int>a(n+1),b(m+1);
        int tot=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],tot+=a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i],tot+=b[i];
        // 4 5 6
        // 1 2 3
        // 4 5 6
        // 1 2 3
        // 3 5 6
        // 1 2 4
        //  
        sort(all(a));
        sort(all(b));
        int sum1=0,l=1,sum2=0;
        if(k&1)k=1;
        else k=2;
        while(l<=k){
            sum1=0;
            if(l&1){
                if(a[1]<b[m])
                    swap(a[1],b[m]);
                for(int i=1;i<=n;i++)
                    sum1+=a[i];
                sort(all(a));
                sort(all(b));
                sum2=tot-sum1;
            }
            else{
                if(b[1]<a[n])
                    swap(a[n],b[1]);
                for(int i=1;i<=n;i++)
                    sum1+=a[i];
                // sort(all(b));
                // sum1=tot-sum2;
            }
            l++;
        }
        cout<<sum1<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}