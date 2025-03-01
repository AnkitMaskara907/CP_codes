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
    vector<int>dp1(100001),dp2(100001);
    dp1[1]=1,dp2[1]=1;
        for(int i=2;i<=100000;i++){
            dp1[i]=dp2[i-2];
            dp2[i]=dp1[i-1]+1;
        }
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        int sum=0,odd=0,even=0;
        
        // cout<<a[1]<<" ";
        // 1 odd=1
        // 2 odd-> 0
        // 3 odd-> 1
        // 4 odds-> 2 odds + 1 even -> 1 + 1 odd + 1 even -> 2
        // 5 odds-> 3 odds+ 1 even-> 2 odds + 1 even +1 ->  1
        // 6 odds-> 4 odds-> 3 odds + 1-> 1 odd + 1 even +1-> 2
        // 7 odds-> 5 odds -> 4 odds + 1 even +1-> 2 odds + 2 even + 1-> 3
        sum=a[1];cout<<sum<<" ";
        if(sum&1)odd++;else even++;
        if(n>1){
            sum+=a[2];
            cout<<(sum/2)*2<<" ";
            if(a[2]&1)odd++;
            else even++;
        }
        for(int i=3;i<=n;i++){
            if(a[i]&1)odd++;
            else even++;
            sum+=a[i];
            cout<<sum-dp1[odd]<<" ";
        }
        cout<<"\n";
        // cerr<<dp1[4]<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}