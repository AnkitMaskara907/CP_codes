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
        vector<pair<int,int>>A(4);
        vector<int>ans(4);
        for(int i=1;i<=3;i++)cin>>A[i].F,A[i].S=i;
        int a,b,c;
        a=A[1].F,b=A[2].F,c=A[3].F;
        // sort(all(A));
        // // c->a,c->b,b->a;
        // // c-a
        // b+=a;
        // c-=a;
        // a=0;
        // if(abs(b-c)%2==0)
        //     ans[A[1].S]=1;
        // if(b>c){
        //     if(c%2==0)ans[A[2].S]=1;
        // }
        // else if((b%2==0)&&(c>b))ans[A[3].S]=1;
        // else if(b==c)ans[A[1].S]=1;
        // // c-b
        // a=A[1].F,b=A[2].F,c=A[3].F;
        // a+=b;
        // c-=b;
        // b=0;
        // if(a>c){
        //     if(c%2==0)ans[A[1].S]=1;
        // }
        // else if((a%2==0)&&(c>a))ans[A[3].S]=1;
        // else if(a==c)ans[A[2].S]=1;
        // // b-a
        // a=A[1].F,b=A[2].F,c=A[3].F;
        // b-=a;
        // c+=a;
        // a=0;
        // if(b%2==0)ans[A[3].S]=1;
        if(abs(a-b)%2==0)ans[3]=1;
        if(abs(b-c)%2==0)ans[1]=1;
        if(abs(a-c)%2==0)ans[2]=1;
        cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<"\n";
        // 0 3 7 
        // 1 2 6
        // 0 3 5
        // 1 2 4
        // 0 3 3
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}