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
const ll inf=(1000000000000000000);
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

    // int t,n,i,j,k,f;
    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;tc++){
        // 
        int n,W;
        cin>>n>>W;
        vector<pair<int,int>>elements(n);
        for(int i=0;i<n;i++)
            cin>>elements[i].first>>elements[i].second;
        int maxValue=1000*n+1;
        vector<int>minWeight(maxValue,inf);
        minWeight[0]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int currWeight=elements[i].first,currValue=elements[i].second;
            for(int val=maxValue;val>=currValue;val--){
                if(minWeight[val-currValue]!=inf){
                    minWeight[val]=min(minWeight[val],minWeight[val-currValue]+currWeight);
                    if(minWeight[val]<=W)
                        ans=max(ans,val);
                }
            }
        }
        cout<<ans;
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}