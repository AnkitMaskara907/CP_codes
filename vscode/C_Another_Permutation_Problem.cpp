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
        ll ans=0;
        vector<int>a(n+1);
        set<int>s;
        for(int i=1;i<=n;i++)
            s.insert(-i);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                auto it=s.find(-j);
                s.erase(it);
                int J=n+1,mx=j*i;
                ll tmp=0;
                bool poss=true;
                for(int I=n;I>=1;I--){// A[I]=J
                    if(I==i)continue;
                    J--;
                    if(s.find(-J)==s.end()){I++;continue;}
                    if(J*I>mx){
                        int q=mx/I;
                        auto it=s.lower_bound(-q);
                        if(it==s.end())
                            poss=false;
                        else {
                            q=*it;
                            // used[q]=1;
                            q*=-1;
                            tmp+=I*q;
                            J++;
                            s.erase(it);
                            continue;
                        }
                    }
                    if(poss){
                        tmp+=J*I;
                        s.erase(s.find(-J));
                    }
                    else break;
                }
                if(poss)
                    ans=max(ans,tmp);
                for(int I=1;I<=n;I++)s.insert(-I);
            }
        }
        cout<<ans<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}