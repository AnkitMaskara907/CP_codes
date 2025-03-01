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
    // cin>>t;
    t=1;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int>count1(10);
        for(auto x:a)
            count1[x-'0']++;
        sort(all(a),greater<char>());
        vector<int>count2=count1;
        if(a<=b)
            cout<<-1;
        else{
            // cerr<<b<<"\n";
            int mxind=0;
            for(int i=0;i<n;i++){
                int d=b[i]-'0';
                int j;
                for(j=d+1;j<10;j++){
                    if(count1[j]){
                        mxind=i;
                        break;
                    }
                }
                
                if(count1[d]==0)
                    break;
                count1[d]--;
            }
            // cerr<<mxind;
            count1=count2;
            if(b[0]=='0'){
                for(int i=1;i<=9;i++){
                    if(count1[i])
                        cout<<i,count1[i]--;
                }
                for(int i=0;i<=9;i++){
                    while(count1[i]--)
                        cout<<i;
                }
                break;
            }
            for(int i=0;i<mxind;i++)
                cout<<b[i],count2[b[i]-'0']--;
            int nx=b[mxind]-'0';
            for(int i=nx+1;i<=9;i++){
                if(count2[i]){
                    cout<<i;
                    count2[i]--;
                    break;
                }
            }
            for(int i=0;i<=9;i++){
                while(count2[i]--)cout<<i;
            }
        }

    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}