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
vector<int>primes={2,3,5,7,11,13,17,19,23,29};
map<int,int>fre;
ll ans=0;
// const ll inf=(1000000000000000000);
typedef pair<ll,ll> pairs;
#define varval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
inline ll mod(ll a){
    return (a-MOD*(a/MOD));
}
int gcd(int a,int b){
    if(b==0)return a;
    if(a==0)return b;
    if(b%a==0)
        return a;
    return gcd(b%a,a);
}
ll power(ll a, ll b){ll res=1;a=mod(a);while(b>0){if(b&1){res=mod(res*a);b--;}a=mod(a*a);b>>=1;}
        return res;}
    void subs(int prInd,int ele,int lcm){
        // if gcd(ele,lcm)==1 && 
        if(prInd>=10||ele>30)return;
        if(gcd(ele,lcm)==1)
            
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        for(auto x:nums)
            fre[x]++;
        return (subs(0,2,1)*power(2,fre[1]))%MOD;
    }
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    vector<int>nums;
    for(;;){
        cin>>k;
        if(k==-1)break;
        nums.push_back(k);
    }
    numberOfGoodSubsets(nums);
    cout<<ans;
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}