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
vector<int>nonPrimes;
vector<bool>notPrime(400001);
void getPrimes(){
    nonPrimes.push_back(1);
    for(int i=2;i<=400000;i++){
        if(notPrime[i])
            nonPrimes.push_back(i);
        for(int j=i*i;j<=400000;j+=i)
            notPrime[j]=1;
    }
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    getPrimes();
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<vector<int>>graph(n+1);
        vector<int>ans(n+1),vis(n+1);
        bool poss=true;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ans[1]=1;
        set<int>elements;
        for(int i=2;i<=2*n;i++)
            elements.insert(i);
        function<void(int)> dfs=[&](int node){
            vis[node]=1;
            int curr=0;
            for(auto child:graph[node]){
                if(!vis[child]){
                    while(nonPrimes.size()>curr&&elements.find(ans[node]+nonPrimes[curr])==elements.end())
                        curr++;
                    if(curr==nonPrimes.size()){
                        poss=false;
                        return;
                    }
                    ans[child]=ans[node]+nonPrimes[curr++];
                    elements.erase(ans[child]);
                    dfs(child);
                }
                if(!poss)
                    return;
            }
        };
        dfs(1);
        if(!poss){
            cout<<-1<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}