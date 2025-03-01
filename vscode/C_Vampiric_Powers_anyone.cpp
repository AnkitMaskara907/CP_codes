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
struct Trie
{
    int value;  // Only used in leaf nodes
    Trie *arr[2];
};
 
// Utility function to create a Trie node
Trie *newNode()
{
    Trie *temp = new Trie;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 

void insert(Trie *root, int pre_xor)
{
    Trie *temp = root;
 
    for (int i=7; i>=0; i--)
    {

        bool val = pre_xor & (1<<i);
 

        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
 
        temp = temp->arr[val];
    }
 

    temp->value = pre_xor;
}
 
int query(Trie *root, int pre_xor)
{
    Trie *temp = root;
    for (int i=7; i>=0; i--)
    {
        
        bool val = pre_xor & (1<<i);
 
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}
 

int maxXor(int arr[], int n)
{
    Trie *root = newNode();
    insert(root, 0);
 
    int result = INT_MIN, pre_xor =0;
 
    for (int i=0; i<n; i++)
    {
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor);
 
        result = max(result, query(root, pre_xor));
    }
    return result;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<maxXor(a,n)<<"\n";
    
        // 8 2 4 12 1
        // 8 2 4 12 1 1 
        // 8 2 4 12 1 1 10
        // 8 2 4 12 1 1 10 14
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}