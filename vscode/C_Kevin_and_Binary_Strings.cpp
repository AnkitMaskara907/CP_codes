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
        string s;
        cin>>s;
        n=s.length();
        vector<int>zeroes;
        int firstZ=0;
        while(firstZ<n&&s[firstZ]=='1')
            firstZ++;
        if(firstZ==n){
            cout<<1<<" "<<n<<" "<<1<<" "<<1<<"\n";
            continue;
        }
        for(int i=firstZ;i<n;i++){
            if(s[i]=='0')
                zeroes.push_back(i-firstZ);
        }
        int lengthSub=n-firstZ;
        vector<pair<string,int>>subs;
        for(int i=0;i<firstZ;i++){
            int start=i,end=i+lengthSub;
            int I=firstZ;
            string tmp;
            for(;start<end;start++,I++){
                if(s[start]==s[I])
                    tmp+="0";
                else tmp+="1";
            }
            subs.push_back({tmp,i+1});
        }
        sort(all(subs));
        // for(auto x:subs)
        //     cerr<<x.first<<" ";
        cout<<1<<" "<<n<<" "<<subs.back().second<<" "<<subs.back().second+lengthSub-1<<"\n";
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}