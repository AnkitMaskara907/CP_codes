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
const int MOD=98244353;
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
        cin>>n;
        string s;
        cin>>s;

        // 3131
        // 31113
        // 311111
        bool poss=true;
        for(int i=1;i<n;i+=2){
            if(s[i]!='1')
                poss=false;
        }
        if(!poss){
            cout<<-1;
            continue;
        }
        s+='1';
        vector<int>ones(n+2);
        for(int i=n-1;i>=1;i--){
            int val=s[i]-'0';
            if(val==1){
                ones[i]=1+((ones[i+2]+1)*(s[i+1]-'0'-1));
            }
            else ones[i]=ones[i+1]+1;
        }
        // for(int i=1;i<=n;i++)
        //     cerr<<ones[i]<<" ";
        cout<<(ones[1]+ones[3]+1)%MOD<<"\n";
        // 3 2 1 1 1
        // 3321
        // 333332
        // 
        // 1 3 3 1 3
        // 1113333111
        // 11111333333311
        // 1111111333333333333333333
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}