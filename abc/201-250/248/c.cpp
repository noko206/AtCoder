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

ll dp[55][2505];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    dp[0][0] = 1;
    REP(i, n){
        REP(j, 1, m + 1){
            REP(s, k + 1){
                if(j + s > k) break;
                dp[i + 1][j + s] += dp[i][s];
                dp[i + 1][j + s] %= MOD;
            }
        }
    }
    ll ans = 0;
    REP(i, k + 1){
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
}