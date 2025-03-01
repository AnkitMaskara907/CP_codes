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
        int a,b,c,d;
        // vector<pair<int,int>>ele(4);
        // for(int i=0;i<4;i++){cin>>ele[i].F;ele[i].S=i;}
        // sort(all(ele));
        // for(auto x:ele)cerr<<x.F<<" ";
        // cerr<<"\n";
        cin>>a>>b>>c>>d;
        bool inter=false;
        // for(int i=0;i<4;i++){
        //     if(ele[i].S==0)a=i;
        //     if(ele[i].S==1)b=i;
        //     if(ele[i].S==2)c=i;
        //     if(ele[i].S==3)d=i;

        // }
        if(c>d)swap(c,d);
        if(a>b)swap(a,b);
        int curr=0;
        vector<int>ele(4);
        // ele[0]=1;
        for(int i=a;curr<4;i=(i)%12+1){
            if(i==a)
                ele[0]=curr++;
            else if(i==b)
                ele[1]=curr++;
            else if(i==c)
                ele[2]=curr++;
            else if(i==d)
                ele[3]=curr++;
        }
        // cerr<<a<<b<<c<<d<<"\n";
        a=ele[0],b=ele[1],c=ele[2],d=ele[3];
        if(c>d)swap(c,d);
        if(a>b)swap(a,b);
        if(c<b){
            if((c>a)&&(d>b))
                inter=true;
        }
        if(inter)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}