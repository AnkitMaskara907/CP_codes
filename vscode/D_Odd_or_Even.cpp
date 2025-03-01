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
int query(vector<int>&V,int l,int r){
    cout<<"? ";
    int X=0;
    for(auto x:V)
        cout<<x<<" ";
    for(;l<=r;l++)
        cout<<l<<" ";
    cout<<endl;
    int k;
    cin>>k;
    return k;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>k;
        vector<int>a(n+1);
        vector<int>ver;
        vector<int>store;
        int K=k;
        int x=0;
        for(int i=1;K>0;i++){
            vector<int>tmp;
            if(i>1)
                x=x^(ver[2*i-3]^ver[2*i-4]);
            int res1=query(store,i,i+K-1);
            int res2=query(store,i+1,i+K);
            ver.push_back(x^res1);
            ver.push_back(x^res2);
            store.push_back(i);
            store.push_back(i+K);
            K-=2;
        }
        // 1, 0, 1, 1, 0, 1
        int X=0;
        while(!store.empty()){
            int tempx=0;
            for(int i=1;i<=2;i++){
                int ind=store.back();
                store.pop_back();
                a[ind]=(X^ver.back());
                tempx^=a[ind];
                ver.pop_back();
            }
            X^=tempx;
        }
        X=0;
        for(int i=1;i<k;i++)
            X=X^a[i],store.push_back(i);
        for(int i=k+2;i<=n;i++)
            a[i]=(X^query(store,i,i));
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}