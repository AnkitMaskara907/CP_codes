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
        cin>>n;
        vector<pair<pair<int,int>,int>>a(n+1);
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            a[i]={{x,y},i};
        }
        vector<int>room(n+1);
        sort(all(a));
        int cnt=0;
        map<int,set<int>>allocated;
        multiset<int>last;
        for(int i=1;i<=n;i++){
            int y=a[i].F.S,x=a[i].F.F,ind=a[i].S;
            auto it=last.upper_bound(-x);
            if(it!=last.end()){
                allocated[-y].insert(*(allocated[*it].begin()));
                room[ind]=(*(allocated[*it].begin()));
                auto it2=allocated[*it].find(room[ind]);
                allocated[*it].erase(it2);
                
                // cerr<<"For x="<<x<<",the it is:"<<*it<<"\n";
                last.erase(it);
            }
            else {
                k=last.size();
                room[ind]=k+1;
                allocated[-y].insert(room[ind]);
            }
            last.insert(-y);
            // cerr<<"Room allocated for "<<x<<" "<<y<<" is: "<<room[ind]<<"\n";
            // cerr<<x<<" "<<y<<" "<<allocated[-y]<<"\n";
        }

        cout<<last.size()<<"\n";
        for(int i=1;i<=n;i++)
            cout<<room[i]<<" ";
    }
    // 1-> {6,6},{5,5},{10,10}
    // 2-> {6,6}
    // 3-> {}
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}