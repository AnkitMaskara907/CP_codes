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
        vector<int>P(n+1);
        for(int i=1;i<=n;i++)
            cin>>P[i];
        vector<pair<int,int>>LD(m+1);
        for(int i=1;i<=m;i++)
            cin>>LD[i].first;
        for(int i=1;i<=m;i++)
            cin>>LD[i].second;
        sort(all(P));
        // start from the beginning and we would get the coupon such that the element's price falls in the range and has the max possible discount
        sort(all(LD));
        vector<int>mark(n+1,-1);
        // 1-> coupon applied
        // 0-> coupon could be applied but waited
        // -1 -> coupon cannot be applied
        int ptr1=1,ptr2=1;
        long long ans=0;
        set<pair<int,int>>s;
        for(ptr1=1;ptr1<=n;ptr1++){
            while((ptr2<=m)&&(LD[ptr2].first<=P[ptr1])){
                s.insert({LD[ptr2].second,ptr2});
                ptr2++;
            }
            ans+=P[ptr1];
            if(s.empty())
                continue;
            mark[ptr1]=0;
            auto it=s.upper_bound({P[ptr1],-1});
            if(it==s.begin())
                continue;
            it--;
            mark[ptr1]=1;
            ans-=(*it).first;
            s.erase(it);
            // cerr<<ans<<"\n";
        }
        for(int ptr1=n;ptr1>0;ptr1--){
            if(s.empty())
                break;
            while(ptr2>0&&(LD[ptr2].first>P[ptr1])){
                auto it=s.find({LD[ptr2].second,ptr2});
                if(it!=s.end())
                    s.erase(it);
                ptr2--;
            }
            if(mark[ptr1]!=0)
                continue;
            s.erase(--s.end());
            ans-=P[ptr1];
        }
        cout<<ans;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}