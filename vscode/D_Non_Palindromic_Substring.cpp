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
struct manacher{
    vector<int>p;
    void run_manacher(string s){
        int n=s.length();
        p.assign(n,1ll);
        int l=0,r=2;
        for(int i=1;i<n;i++){
            p[i]=max(1ll,min(r-i,p[l+r-i]));
            while((i-p[i]>=0)&&(i+p[i]<n)&&(s[i-p[i]]==s[i+p[i]]))
                p[i]++;
            if(i+p[i]>r)
                r=i+p[i],l=i-p[i];
        }
            
    }
    void build(string s){
        string t;
        for(char x:s){
            t+=string("#")+x;
        }
        run_manacher(t+"#");
    }
    int getLongest(int c,bool odd){
        int ind=2*c+1+(!odd);
        return p[ind]-1;
    }
    bool isPalin(int l,int r){
        // //cerr<<getLongest((l+r)/2,(l%2==r%2))<<"\n";
        return ((r-l+1)<=getLongest((l+r)/2,(l%2==r%2)));
    }
};
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int q;
        cin>>n>>q;
        vector<int>evensum(n+1),oddsum(n+1);
        for(int i=2;i<=n;i++){
            if(i&1)
                evensum[i]=evensum[i-1],oddsum[i]=oddsum[i-1]+i;
            else evensum[i]=evensum[i-1]+i,oddsum[i]=oddsum[i-1];
        }
        string s;
        manacher m;
        cin>>s;
        m.build(s);
        vector<vector<int>>tot(n+1,vector<int>(27)),alt(n+1,vector<int>(27));
        for(int i=1;i<=n;i++){
            for(int ch=0;ch<26;ch++){
                tot[i][ch]=tot[i-1][ch]+(s[i-1]==(char)('a'+ch));
                alt[i][ch]=((i>2)?(alt[i-2][ch]):0)+(s[i-1]==(char)('a'+ch));
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int len=r-l+1;
            int ch1=char(s[l-1])-'a',ch2=char(s[l])-'a';
            ll ans=0;
            // //cerr<<tot[r][ch1]-tot[l-1][ch1]<<"\n";
            if(tot[r][ch1]-tot[l-1][ch1]==len)
                ans=0;
            else{
                ans=evensum[len-1];
                if((alt[r-(r+l)%2][ch1]+1-alt[l][ch1]!=(len+1)/2)||(alt[r-(r+l+1)%2][ch2]+1-alt[l+1][ch2]!=(len)/2))
                    ans+=oddsum[len-1];
                // cerr<<alt[<<"\n";
                ans+=m.isPalin(l-1,r-1)?0:len;
                // cerr<<l<<" "<<r<<" "<<m.isPalin(l,r)<<"\n";
            }
            cout<<ans<<"\n";
        }
    }
    // //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}