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

int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        
        int a,b;
        cin>>a>>b;
        int m;
        cin>>m;
        int ans=0;

        for(int digits=1;digits<=17;digits+=2){
                bool poss=true;
            for(int start=1;start<=9&&(poss);start++){
                int num=0;
                for(int digcnt=0;digcnt<(digits+1)/2;digcnt++){
                    if(start+digcnt>9){
                        poss=false;
                        break;
                    }
                    num=(num*10)+(start+digcnt);
                }
                if(!poss)break;
                int peak=num%10;
                for(int digcnt=1;digcnt<=digits/2;digcnt++)
                    num=(num*10)+(peak-digcnt);
                // cerr<<num<<"\n";
                if(num<a)
                    continue;
                if(num>b)
                    continue;
                if((num%m)==0)
                    ans++;
                if(!poss)
                    break;
            }
            
        }
        cout << "Case #"<<tc<<": "<<ans<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}