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
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        int m;
        cin>>n>>m;
        vector<string>a(n);
        vector<int>lents(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            lents[i]=a[i].length();
            lents[i]+=(i>0)?lents[i-1]:0;
        }
        vector<vector<int>>fre(26,vector<int>(lents[n-1]));
        int curr=0;
        for(int i=0;i<n;i++){
            for(char x:a[i])
                fre[x-'a'][curr++]++;
        }
        for(int i=0;i<26;i++){
            for(int curr=1;curr<lents[n-1];curr++)
                fre[i][curr]+=fre[i][curr-1];
        }
        while(m--){
            int l,r;
            cin>>l>>r>>k;
            l-=2,r--;
            char ans='z';
            for(int i=0;i<26;i++){
                int diff=fre[i][lents[r]-1]-(l>=0)*fre[i][lents[l]-1];
                k-=diff;
                if(k<=0){
                    ans='a'+i;
                    break;
                }
            }
            // cerr<<k<<"\n";
            cout<<ans<<"\n";
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}