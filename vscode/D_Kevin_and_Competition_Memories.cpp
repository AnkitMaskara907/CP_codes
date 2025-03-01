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
        cin>>n>>m;
        vector<int>ratings(n),difficulties(m);
        int kevin=0;
        for(int i=0;i<n;i++)
            cin>>ratings[i];
        for(int i=0;i<m;i++)
            cin>>difficulties[i];
        kevin=ratings[0];

        sort(all(ratings));
        sort(all(difficulties));

        // find the number of other users who can solve the problem

        vector<int>othersCanSolve(m);
        for(int i=0;i<m;i++){
            if(difficulties[i]>kevin){
                int others=ratings.end()-lower_bound(all(ratings),difficulties[i]);
                othersCanSolve[i]=others;
            }
        }
        sort(all(othersCanSolve));

        vector<int>ans(m+1);
        for(int k=1;k<=m;k++){
            for(int idx=k-1;idx<m;idx+=k)
                ans[k]+=othersCanSolve[idx]+1;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}