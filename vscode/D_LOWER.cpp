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
struct query{
    int opt,ind;
    char ch;
};
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        string s;
        cin>>s;
        bool lower=false,upper=false;
        int q;
        cin>>q;
        vector<query>store;
        vector<int>changed(n),keepsame(n);
        for(int i=1;i<=q;i++){
            int opt,ind;
            char ch;
            cin>>opt>>ind>>ch;
            ind--;
            store.push_back({opt,ind,ch});
        }
        reverse(all(store));
        bool done=false;
        for(int i=0;i<q;i++){
            query obj=store[i];
            if((obj.opt==1)&&(!changed[obj.ind])){
                s[obj.ind]=obj.ch;
                changed[obj.ind]=1;
                if(!done)
                    keepsame[obj.ind]=1;
            }
            else if((obj.opt!=1)&&(!done)){
                if(obj.opt==3)
                    upper=true;
                else lower=true;
                done=true;
            }
        }
        for(int i=0;i<n;i++){
            if(keepsame[i]){
                cout<<s[i];
                continue;
            }
            int diff=0;
            if(s[i]>='a'&&(s[i]<='z'))
                diff=s[i]-'a';
            else diff=s[i]-'A';
            if(upper){
                cout<<char('A'+diff);
            }
            else if(lower)
                cout<<char('a'+diff);
            else cout<<s[i];
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}