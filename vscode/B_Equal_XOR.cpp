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
    // 1 1 2 2 3 4| 3 4 5 5 6 6
    // k=3
    // print 6 elements
    // 
    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>k;
        vector<int>a(2*n+1);
        for(int i=1;i<=2*n;i++)
            cin>>a[i];
        map<int,int>ind;
        vector<int>diff,samel,samer,l,r;
        for(int i=1;i<=n;i++){
            if(ind[a[i]])
                samel.push_back(a[i]);
            ind[a[i]]=i;
        }
        for(int i=n+1;i<=2*n;i++){
            if(ind[a[i]]>n)
                samer.push_back(a[i]);
            else if(ind[a[i]]&&(ind[a[i]]<=n))
                diff.push_back(a[i]);
            ind[a[i]]=i;
        }
        k*=2;
        i=0;
        while(k>0&&(i<samer.size())){
            l.push_back(samel[i]);
            l.push_back(samel[i]);
            r.push_back(samer[i]);
            r.push_back(samer[i]);
            k-=2;i++;
        }
        for(int i=0;k;i++){
            l.push_back(diff[i]);
            r.push_back(diff[i]);
            k--;
        }
        for(auto x:l)
            cout<<x<<" ";
        cout<<"\n";
        for(auto x:r)
            cout<<x<<" ";
        cout<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}