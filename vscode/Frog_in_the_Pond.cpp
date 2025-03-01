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
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<int>maxDist(n+1),jumps(n);
        int currJumps=0;
        maxDist[0]=1;
        for(int i=0;i<n;i++)
            cin>>jumps[i];
        
        for(int i=0;i<n;i++){
            if(i==maxDist[currJumps])
                currJumps++;
            maxDist[currJumps+1]=max({maxDist[currJumps+1],i+1+jumps[i],maxDist[currJumps]});
            
        }
        while(maxDist.back()==0)
            maxDist.pop_back();
        // for(auto x:maxDist)
        //     cerr<<x<<" ";
        int q;
        cin>>q;
        vector<pair<int,int>>steps(q);
        vector<int>minSteps(q);
        int cnt=0;
        while(q--){
            // cin>>steps[q];
            int step;
            cin>>step;
            // steps[cnt]={step,cnt};cnt++;
            int l=0,r=maxDist.size(),ans=0;
            r--;
            while(l<=r){
                int mid=(l+r)/2;
                if(maxDist[mid]>=step){
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            cout<<ans<<"\n";
        }
        // sort(all(steps));
        // int curr=0;
        // q=steps.size();
        // for(int i=0;i<q;i++){
        //     while(maxDist[curr]<steps[i].first)
        //         curr++;
        //     minSteps[steps[i].second]=curr;
        // }
        // for(int i=0;i<q;i++)
        //     cout<<minSteps[i]<<"\n";
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}