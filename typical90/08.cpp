#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll dp[10][100100];
const string atcoder = "atcoder";

int main(){
    int n;
    string s;
    cin >> n >> s;
    REP(i, n){
        dp[0][i] = 1;
    }
    REP(i, 1, 8){
        REP(j, n){
            if(j > 0){
                dp[i][j] = dp[i][j - 1];
            }
            if(atcoder[i - 1] == s[j]){
                dp[i][j] += dp[i - 1][j];
            }
            dp[i][j] %= MOD;
        }
    }
    // REP(i, 8){
    //     REP(j, n){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[7][n - 1] << endl;
}