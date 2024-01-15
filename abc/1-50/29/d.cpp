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
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

ll dp[11][2][11];

int main(){
    string N;
    cin >> N;
    int n = N.length();
    dp[0][0][0] = 1;
    REP(i, n){
        REP(j, 10){
            dp[i + 1][1][j] += dp[i][1][j] * 9;
            dp[i + 1][1][j + 1] += dp[i][1][j];

            int ni = (N[i] - '0');

            if(ni > 1){
                dp[i + 1][1][j] += dp[i][0][j] * (ni - 1);
                dp[i + 1][1][j + 1] += dp[i][0][j];
            }
            if(ni == 1){
                dp[i + 1][1][j] += dp[i][0][j];
            }

            if(ni == 1){
                dp[i + 1][0][j + 1] += dp[i][0][j];
            }
            else{
                dp[i + 1][0][j] += dp[i][0][j];
            }
        }
    }

    ll ans = 0;
    REP(i, 2){
        REP(j, 1, 10){
            ans += dp[n][i][j] * j;
        }
    }
    cout << ans << endl;
}