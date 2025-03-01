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
        int x,y;
        cin>>n>>x>>y;
        vector<int>a(n+1),present(n+1);
        vector<vector<int>>dependsOn(n+1),dependedBy(n+1);
        dependsOn[1].push_back(2);
        dependsOn[1].push_back(n);
        dependedBy[n].push_back(1);
        dependedBy[2].push_back(1);

        for(int i=2;i<=n;i++){
            dependsOn[i].push_back(i-1);
            dependsOn[i].push_back(i%n+1);
            dependedBy[i-1].push_back(i);
            dependedBy[i%n+1].push_back(i);
        }
        dependsOn[x].push_back(y);
        dependsOn[y].push_back(x);

        dependedBy[x].push_back(y);
        dependedBy[y].push_back(x);

        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            present[front]=0;
            set<int>s={0,1,2,3};
            for(auto x:dependsOn[front]){
                s.erase(a[x]);
            }
            int mex=*(s.begin());
            if(mex!=a[front]){
                for(auto y:dependedBy[front]){
                    if(!present[y]){
                        q.push(y);
                        present[y]=1;
                    }
                }
            }
            a[front]=mex;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}