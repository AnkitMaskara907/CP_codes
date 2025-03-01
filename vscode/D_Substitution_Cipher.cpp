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
const int MOD=(998244353);
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
        string s;
        cin>>s>>k;
        // s="#"+s;
        int n=s.length(),decodings=1;
        vector<int>dp(n);
        dp[0]=1;
        int addedPrev=-1;
        for(int i=1;i<n;i++){
            
            dp[i]=dp[i-1];
            if(s[i]=='0'){
                if(addedPrev==(i-1)){
                    dp[i]--;
                    dp[i-1]--;
                }
                continue;
            }

            if(s[i]!='?'){
                int num=s[i]-'0';
                if(num>5){
                    if(s[i-1]=='?'||s[i-1]=='1'){// using prev digit
                        if(i>1)
                            dp[i]=(dp[i]+dp[i-2]);
                        else dp[i]=(dp[i]+1);
                        addedPrev=i;
                    }
                }
                else {
                    if(s[i-1]=='?'||s[i-1]=='1'||s[i-1]=='2'){// using prev digit
                        if(i>1)
                            dp[i]=(dp[i]+dp[i-2]);
                        else dp[i]=(dp[i]+1);
                        addedPrev=i;
                    }
                }
            }
            else {
                if(s[i-1]=='1'||s[i-1]=='2'||s[i-1]=='?'){
                    if(i>1)
                        dp[i]=(dp[i]+dp[i-2])%MOD;
                    else dp[i]=(dp[i]+1);
                    addedPrev=i;
                }
            } 
        }
        string ans;
        for(int i=0;i<n;i++)[
            if(s[i]=='?')
                
        ]
        for(int i=0;i<n;i++)
            cerr<<dp[i]<<" ";
        cerr<<"\n";
        cout << "Case #"<<tc<<": "<<dp[n-1]<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}