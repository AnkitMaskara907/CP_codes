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
vector<vector<int>>a;
vector<char>let;

int dfs(int node){
    int cnt=0;
    if((a[node][0]==a[node][1])&&(a[node][0]==0))return 0;
    if(let[node]=='U')
        cnt++;
    int L=a[node][0],R=a[node][1];
    if(L==0)
        L=MOD;
    else L=dfs(L);
    if(R==0)R=MOD;
    else R=dfs(R);
    if(L<R){
        if(let[node]!='L')
            return 1+L;
        else return L;
    }
    else if(L==R)
        return cnt+L;
    else {
        if(let[node]!='R')
            return 1+R;
        else return R;
    }
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        a.resize(n+1);
        let.resize(n+1);
        for(int i=1;i<=n;i++)cin>>let[i];
        for(int i=1;i<=n;i++){
            int L,R;
            cin>>L>>R;
            a[i].push_back(L);
            a[i].push_back(R);
        }
        cout<<dfs(1)<<"\n";

        a.clear();
        let.clear();
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}