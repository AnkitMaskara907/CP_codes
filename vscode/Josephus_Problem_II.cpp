// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
#define ll int
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
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
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
	return res;}
 
class segtree{
    public:
    ll sz,n;
    vector<ll>sum;
    segtree(ll N){
        sz=1;n=N;
        while(sz<n)sz*=2;
        sz*=2;
        sum.resize(sz);
    }
    void build(vector<ll>&a,ll lx,ll rx,ll node,ll &curr){
        if(rx-lx==1){
            sum[node]=a[curr++];
            return;
        }
        ll mid=(lx+rx)/2;
        build(a,lx,mid,2*node+1,curr);
        build(a,mid,rx,2*node+2,curr);
        sum[node]=sum[2*node+1]+sum[2*node+2];    
        return;
    }
    void update(ll lx,ll rx,ll node,ll ind,ll val){
        if(rx<=ind||lx>ind)
            return;
        if(rx-lx==1){
            sum[node]=val;
            return;
        }
        ll mid=(lx+rx)/2;
        update(lx,mid,2*node+1,ind,val);
        update(mid,rx,2*node+2,ind,val);
        sum[node]=sum[2*node+1]+sum[2*node+2];
        return;
    }
    ll query(ll l,ll r,ll lx,ll rx,ll node){
        if(rx<=l||lx>=r)
            return 0ll;
        ll mid=(lx+rx)/2;
        if(lx>=l&&rx<=r)
            return sum[node];
        return query(l,r,lx,mid,2*node+1)+query(l,r,mid,rx,2*node+2);
    }
    void build(vector<ll>&a){
        ll curr=0;
        build(a,0,n,0,curr);
        return;
    }
    ll query(ll l,ll r){
        ll tot=0;
        return query(l,r,0,n,0);
    }
    void update(ll ind,ll val){
        update(0,n,0,ind,val);
    }
};
int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// auto start=high_resolution_clock::now();
	// ll duration=duration_cast<milliseconds>(end-start).count();
 
	ll t,n,i,j,k,f;
	// cin>>t;
    t=1;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>k;
        k%=n;
        segtree tree(n);
        vc a(n,1);
        tree.build(a);
        int curr=-1,cnt=0;
        // cerr<<tree.query(0,1);
        while(cnt++<n){
            int tmp=k+1;
            while(tmp){
                int ind=-1,l=curr+1,r=n;
                while(l<=r){
                    int mid=(l+r)/2;
                    int sum=tree.query(curr+1,mid);
                    if(sum<tmp)
                        ind=mid,l=mid+1;
                    else r=mid-1;
                }
                tmp-=tree.query(curr+1,ind+1);
                curr=ind;
                if(curr==n)curr=-1;
            }
            tree.update(curr,0);
            cout<<curr+1<<" ";
        }
		// cout<<"Case #"<<tc<<": ";
	}
}