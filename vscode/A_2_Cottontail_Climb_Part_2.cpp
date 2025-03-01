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
int ans=0;
// vector<vector<int>>dp(18,vector<int>(10));
int a,b,m;
// dp[currLen][last]
void getAns(int curr,int len,int currLen){
    // cerr<<curr<<" "<<len<<" "<<currLen<<"\n";
    int last=curr%10;
    if(curr>b)
        return;
    if(currLen==len){
        if(curr<a)return;
        // cerr<<curr<<"\n";
        if((curr%m)==0)
            ans++;
        return;
    }
    // 121, 132, 131
    for(int i=0;i<=9;i++){
        int tmpcr=curr;
        if((last==0)&&(i==0))continue;
        if(currLen<len/2||((currLen==len/2)&&(i>0))){
            if(last+i>9)
                break;
            tmpcr=curr*10+last+i;
        getAns(tmpcr,len,currLen+1);        
        }
        else if((currLen>(len+1)/2)||((currLen==(len+1)/2)&&(i>0))){
            if(last-i<=0)
                break;
            tmpcr=curr*10+last-i;
            getAns(tmpcr,len,currLen+1);        
        }
    }
    return;
    
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        ans=0;
        cin>>a>>b;
        cin>>m;
        // getAns(0,3,0);
        for(int len=1;len<=17;len+=2){
            // dp.resize(18,vector<int>(10));
            getAns(0,len,0);
        }
        //x 
        // Bs+sort=y
        // y/x>=100
        
        cout << "Case #"<<tc<<": "<<ans<<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}