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
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first<b.first)
        return true;
    if(a.first==b.first){
        if(a.second>b.second)
            return true;
    }
    return false;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        vector<pair<int,int>>ranges(n);
        map<pair<int,int>,int>rangesMap;
        vector<int>marked(n);
        for(int i=0;i<n;i++){
            cin>>ranges[i].first>>ranges[i].second;
            if(rangesMap.find(ranges[i])!=rangesMap.end()){
                marked[i]=1;
                marked[rangesMap[ranges[i]]]=i;
            }
            else rangesMap[ranges[i]]=i;
        }
        vector<int>ans(n);
        // vector<pair<int,int>>sortedRanges=ranges;
        sort(all(ranges),cmp);
        // bool markedPushed=0;
        for(int turn=1;turn<=2;turn++){
            multiset<pair<int,int>>start,end;
            for(int i=0;i<n;i++){
                int index=rangesMap[ranges[i]];
                while(!end.empty()){
                    auto it=(end.begin());
                    pair<int,int>firstEnd=*it;
                    if(firstEnd.first<ranges[i].first){
                        end.erase(it);
                        start.erase({ranges[(*it).second].first,(*it).second});
                    }
                    else break;
                }
                if(!marked[index]&&(!end.empty())){
                    auto it=end.lower_bound({ranges[i].second,-1});
                    if(it!=end.end()){
                        int rightClosest=(*it).first;
                        // cerr<<"tc:"<<tc<<" "<<index<<" "<<ranges[i].second<<" "<<rightClosest<<"\n";
                        ans[index]+=rightClosest-ranges[i].second;
                    }
                }
                start.insert({ranges[i].first,i});
                end.insert({ranges[i].second,i});
            }
            for(auto &range:ranges){
                int idx=rangesMap[range];
                range.first=-range.first;
                range.second=-range.second;
                swap(range.first,range.second);
                rangesMap[range]=idx;
            }
            sort(all(ranges),cmp);
        }
        
        for(auto x:ans)
            cout<<x<<"\n";
        
        // cout << "Case #"<<tc<<": "<< <<"\n";
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}