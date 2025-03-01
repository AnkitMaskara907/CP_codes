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
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int q;
        cin>>n>>q;
        vector<int>a(n+1),nonPermissable(n+1,n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vector<deque<int>>pos(n+1);
        for(int i=1;i<=n;i++){
            if(a[i-1]==a[i]){
                pos[a[i]].pop_back();
                // cerr<<"removed "<<a[i]<<" at index "<<i<<"\n";
            }
            pos[a[i]].push_back(i);
        }
        set<int>indices;
        for(int i=1;i<=n;i++){
            if(pos[i].size())
                pos[i].pop_front();
            if(pos[i].size())
                indices.insert(pos[i].front());
        }
        cerr<<"indices : ";
        for(auto x:indices)
            cerr<<x<<" ";
        cerr<<"\n";
        // 1 2 5 2 3 5 
        // find the first index where the number's first occurence is behind a certain number's second occurence

        int last=1;
        for(int i=1;i<n;i++){
            if(a[i+1]==a[i])
                continue;
            if(pos[a[i]].size()){
                indices.erase(pos[a[i]].front());
                pos[a[i]].pop_front();
                if(pos[a[i]].size())
                    indices.insert(pos[a[i]].front());
            }
            // a c b a c b
            // 1 2 3 2 1 5 4 5 1
            if(indices.empty())
                break;
            auto it =indices.begin();
            if()
            nonPermissable[i]=*it;
            while(last!=i)
                nonPermissable[last++]=nonPermissable[i];
            last=i+1;
        }
        for(int i=1;i<=n;i++)
            cerr<<nonPermissable[i]<<" ";
        cerr<<"\n";
        while(q--){
            int l,r;
            cin>>l>>r;
            if(nonPermissable[l]>r)
                cout<<"YES\n";
            else cout<<"NO\n";
        }

        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}