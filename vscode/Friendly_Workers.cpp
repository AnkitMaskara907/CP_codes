#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define F first
#define S second
#define lld long double
#define vc vector<ll>
#define all(a) a.begin(),a.end()
const int MOD = (1e9 + 7);
typedef pair<ll, ll> pairs;

inline ll mod(ll a) {
    return (a - MOD * (a / MOD));
}

ll power(ll a, ll b) {
    ll res = 1;
    a = mod(a);
    while (b > 0) {
        if (b & 1) {
            res = mod(res * a);
            b--;
        }
        a = mod(a * a);
        b >>= 1;
    }
    return res;
}

struct node {
    ll val;
    node* par;
    ll skills;
    ll wage;
    node() {}
    node(ll val) {
        this->val = val;
        this->par = this;
        this->skills = 0;
        this->wage = 0;
    }
};

node* get(node* curr) {
    if ((curr->par)->val == curr->val)
        return curr;
    return curr->par = get(curr->par);
}

void join(node* a, node* b) {
    node* pa = get(a), * pb = get(b);
    if (pa->val == pb->val) return;
    pa->skills += pb->skills;
    pa->wage += pb->wage;
    pb->par = pa;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, i, j, k, f;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ll m, b;
        cin >> n >> m >> b;
        vector<node> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = node(i);
            cin >> nodes[i].wage;
        }
        for (int i = 0; i < n; i++)
            cin >> nodes[i].skills;
        while (m--) {
            int p, q;
            cin >> p >> q;
            p--; q--;
            join(&nodes[p], &nodes[q]);
        }
        int ans = 0;
        unordered_set<node*> groups;
        for (node& x : nodes) {
            groups.insert(get(&x));
        }
        vector<int> dp(b + 1);
        for (auto grp : groups) {
            for (int j = b; j >= grp->wage; j--)
                dp[j] = max(dp[j], dp[j - grp->wage] + grp->skills);
        }
        cout << dp[b] << "\n";
    }
    return 0;
}
