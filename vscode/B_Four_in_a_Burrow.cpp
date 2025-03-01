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
// #define F first
// #define S second
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
set<string>C,F,none,either;
bool valid(int i,int j){
    return (i<6&&i>=0&&j<7&&j>=0);
}
int result(string &s){
    if(s=="CCCC")
        return 0;
    else if(s=="FFFF")
        return 1;
    return -1;
}
int check(vector<vector<char>>&matrix){
    int whoWon=-1;string s;
    // row
    for(int i=0;i<6;i++){
        s="";
        for(int j=0;j<4;j++)
            s+=matrix[i][j];
        if((whoWon=result(s))!=-1)
            return whoWon;
        for(int j=4;j<7;j++){
            s.erase(s.begin());
            s+=matrix[i][j];
            if((whoWon=result(s))!=-1)
                return whoWon;
        }
    }
    // col
    for (int j = 0; j < 7; j++) {  // Loop over all columns
    for (int i = 0; i <= 6 - 4; i++) {  // Ensure we check from row 0 to row 2
        s = "";
        for (int k = 0; k < 4; k++) {  // Check 4 consecutive cells vertically
            s += matrix[i + k][j];
        }
        if ((whoWon = result(s)) != -1)
            return whoWon;
    }
}
    // diag
    for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 7; j++) {
        // Top-left to Bottom-right diagonal (↘ direction)
        if (i + 3 < 6 && j + 3 < 7) { // Ensuring we have space for 4 cells in diagonal
            s = "";
            for (int diff = 0; diff < 4; diff++) {
                s += matrix[i + diff][j + diff];
            }
            if ((whoWon = result(s)) != -1)
                return whoWon;
        }

        // Top-right to Bottom-left diagonal (↙ direction)
        if (i + 3 < 6 && j - 3 >= 0) { // Ensuring we have space for 4 cells in reverse diagonal
            s = "";
            for (int diff = 0; diff < 4; diff++) {
                s += matrix[i + diff][j - diff];
            }
            if ((whoWon = result(s)) != -1)
                return whoWon;
        }
    }
}

    return whoWon;
}
void feedValue(int whoWon,vector<vector<char>>&matrix){
    string s;
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++)
                s+=matrix[i][j];
        }
        if(whoWon==-1)
            none.insert(s);
        else if(whoWon==0){// C=0
            if(F.find(s)!=F.end()){
                F.erase(s);
                either.insert(s);
            }
            else if(either.find(s)!=either.end())
                ;
            else C.insert(s);
        }
        else if(whoWon==1){
            if(C.find(s)!=C.end()){
                C.erase(s);
                either.insert(s);
            }
            else if(either.find(s)!=either.end())
                ;
            else F.insert(s);
        }
    return;
}
void rec(vector<vector<char>>matrix,int turn,vector<int>lastBlank,int whoWon){
    if(turn>42){
        feedValue(-1,matrix);
        return;
    }
    char ch=(turn&1)?'C':'F';
    for(int col=0;col<7;col++){
        if(lastBlank[col]>-1){
            matrix[lastBlank[col]][col]=ch;
            lastBlank[col]--;
            whoWon=check(matrix);
            if(whoWon!=-1){
                feedValue(whoWon,matrix);
                return;
            }
            rec(matrix,turn+1,lastBlank,whoWon);
            lastBlank[col]++;
            matrix[lastBlank[col]][col]='$';
        }
    }
    return;
}
int32_t main() {
    // your code goes here
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t,n,i,j,k,f;
    vector<vector<char>>matrix(6,vector<char>(7,'$'));
    vector<int>last(7,5);
    rec(matrix,1,last,-1);
    // cin>>t;
    // for(int tc=1;tc<=t;tc++){
    //     string s;
    //     for(int i=1;i<=42;i++){
    //         char ch;
    //         cin>>ch;
    //         s+=ch;
    //     }
    //     char ans='?';
    //     bool poss=true;
    //     for(string c:C){
    //         if(!poss)
    //             break;
    //         for(int i=0;i<42;i++){
    //             if(s[i]!=c[i]&&(c[i]!='$')){
    //                 poss=false;
    //                 break;
    //             }
    //         }
    //     }
    //     if(poss)
    //         ans='C';
    //     poss=true;

    //     for(string f:F){
    //         if(!poss)
    //             break;
    //         for(int i=0;i<42;i++){
    //             if(s[i]!=f[i]&&(f[i]!='$')){
    //                 poss=false;
    //                 break;
    //             }
    //         }
    //     }
    //     if(poss)
    //         ans='F';
    //     poss=true;
    //     for(string e:either){
    //         if(!poss)
    //             break;
    //         for(int i=0;i<42;i++){
    //             if(s[i]!=e[i]&&(e[i]!='$')){
    //                 poss=false;
    //                 break;
    //             }
    //         }
    //     }
    //     if(poss)
    //         ans='?';
    //     poss=true;
    //     for(string n:none){
    //         if(!poss)
    //             break;
    //         for(int i=0;i<42;i++){
    //             if(s[i]!=n[i]&&(n[i]!='$')){
    //                 poss=false;
    //                 break;
    //             }
    //         }
    //     }
    //     if(poss)
    //         ans='0';


    //     cout << "Case #"<<tc<<": "<<ans <<"\n";
    // }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<  "ms\n";
        return 0;
}
C......
C......
C......
C.....C
F..F..F
C..F.FC

CFFFFFF
CFFCFFF
CCCFFCC
CCFFCCC
FFCFCCF
CCCFCFC