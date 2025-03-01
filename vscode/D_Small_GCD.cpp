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
int __gcd(int a,int b){
    if(b==0)return a;
    return __gcd(b,a%b);
}
vector<unordered_set<int>>factors;
void pre(){
    for(int i=2;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            factors[i].insert(j);
        }
    }
    return;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    pre();
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(all(a));
        int ans=0;
        // for(int i=1;i<n-1;i++){
        //     for(int j=i+1;j<n;j++)
        //         ans+=__gcd(a[i],a[j])*(n-j);
        // }
        map<int,int>val;
        for(int i=2;i<n;i++){
            val[a[i]]+=n-i;
        }
        for(int i=1;i<=100000;i++){
            if(val.find(i)==val.end())continue;
            for(int j=i;j<=100000;j+=i){
                if(val.find(j)!=val.end())
                    ans+=__gcd(i,j)*val[j];
            }
        }
        cout<<ans<<"\n";
        
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}