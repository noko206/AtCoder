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
const int MOD = 998244353;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

ll dp[1001001][5];

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        if(y1 == y2){
            dp[0][3] = 1;
        }
        else{
            dp[0][1] = 1;
        }
    }
    else{
        if(y1 == y2){
            dp[0][2] = 1;
        }
        else{
            dp[0][0] = 1;
        }
    }
    REP(i, k){
        dp[i + 1][0] += dp[i][0] * (h - 2 + w - 2);
        dp[i + 1][0] %= MOD;
        dp[i + 1][0] += dp[i][1] * (h - 1);
        dp[i + 1][0] %= MOD;
        dp[i + 1][0] += dp[i][2] * (w - 1);
        dp[i + 1][0] %= MOD;
 
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][1] %= MOD;
        dp[i + 1][1] += dp[i][1] * (w - 2);
        dp[i + 1][1] %= MOD;
        dp[i + 1][1] += dp[i][3] * (w - 1);
        dp[i + 1][1] %= MOD;
 
        dp[i + 1][2] += dp[i][0];
        dp[i + 1][2] %= MOD;
        dp[i + 1][2] += dp[i][2] * (h - 2);
        dp[i + 1][2] %= MOD;
        dp[i + 1][2] += dp[i][3] * (h - 1);
        dp[i + 1][2] %= MOD;
 
        dp[i + 1][3] += dp[i][1];
        dp[i + 1][3] %= MOD;
        dp[i + 1][3] += dp[i][2];
        dp[i + 1][3] %= MOD;
    }
    cout << dp[k][3] << endl;
}