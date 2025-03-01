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

    int t,n,i,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        string s,l,r;
        cin>>s;
        n=s.length();
        int m;
        cin>>m>>l>>r;
        string s2="";
        bool poss=true;
        vector<vector<int>>indices(10);
        for(int i=0;i<n;i++)
            indices[s[i]-'0'].pb(i);
        // int mn2=n+1;
        for(int i=m-1;i>=0;i--){
            int mn=n+1;
            for(char ch=l[i];ch<=r[i]&&poss;ch++){
                int val=ch-'0';
                if(indices[val].empty()){
                    poss=false;
                    break;
                }
                mn=min(mn,indices[val].back());
            }
            if(!poss)break;
            for(char ch='0';ch<='9';ch++){
                int val=ch-'0';
                if(indices[val].empty()){
                    if(ch>=l[i]&&ch<=r[i]){
                    poss=false;break;}
                }
                while((!indices[val].empty())&&indices[val].back()>=mn)
                    indices[val].pop_back();
            }
        }
        if(poss)cout<<"NO\n";
        else cout<<"YES\n";
        
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}