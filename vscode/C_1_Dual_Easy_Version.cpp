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
int myabs(int a){
    if(a>=0)return a;
    return -a;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<int>a(n+1);
        int mn=21,mx=-21,mxind=-1,mnind=-1;
        vector<int>neg,pos;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
            if(a[i]==mx)mxind=i;
            if(a[i]==mn)mnind=i;
            if(a[i]>=0)
                pos.push_back(i);
            else neg.push_back(i);
        }
        int last=a[n];
        // max , last
        // + , - -> sabko max se add kar do
        // -, - ->  
        if(mn>=0){
            cout<<n-1<<"\n";
            for(int i=1;i<n;i++)
                cout<<i+1<<" "<<i<<"\n";
        }
        else if(mx<0){
            cout<<n-1<<"\n";
            for(int i=n;i>1;i--){
                cout<<i-1<<" "<<i<<"\n";
            }
        }
        else {
            // x elements positive, n-x negtive
            int poscnt=pos.size(),negcnt=neg.size();
            
            if(mx>=myabs(mn)&&(poscnt>=negcnt)){
                cout<<n-1+negcnt<<"\n";
                for(auto x:neg){
                    cout<<x<<" "<<mxind<<"\n";
                }
                for(int i=1;i<n;i++)
                    cout<<i+1<<" "<<i<<"\n";
            }
            else if(myabs(mn)>mx&&(negcnt>poscnt)){
                cout<<n-1+pos.size()<<"\n";
                for(auto x:pos)
                    cout<<x<<" "<<mnind<<"\n";
                for(int i=n-1;i>=1;i--)
                    cout<<i<<" "<<i+1<<"\n";
            }
            else {
                // 19 1 , 1 -20
                int cnt=0;
                while(abs(mn)<mx)
                    cnt++,mn*=2;
                
            }
        }
        
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}