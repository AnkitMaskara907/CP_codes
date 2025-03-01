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
        cin>>n;
        vector<int>a(n),ans;
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int>b=a;
        sort(b.begin(),b.end());
        multiset<int>inserted,left;
        for(auto x:a)
            left.insert(x);
        for(int i=0;i<n;i++){
            int leftMin=*(left.begin());
            if(!inserted.empty()){
                int insertedMin=*(inserted.begin());
                if(insertedMin<leftMin||a[i]!=leftMin){
                    inserted.insert(a[i]+1);
                }
                else ans.push_back(a[i]);
            }
            else if(leftMin!=a[i])
                inserted.insert(a[i]+1);
            else ans.push_back(a[i]);
            auto it=left.find(a[i]);
            left.erase(it);
        }
        for(auto x:inserted)
            ans.push_back(x);        
        for(auto x:ans)
            cout<<x<<" ";
        cout<<"\n";
        
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}