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

ll dp[3005][3005];
ll num[3005][3005];

int main(){
    int n, s;
    cin >> n >> s;
    REP(i, n + 1){
        REP(j, 3001){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    num[0][0] = 1;
    REP(i, n){
        int a;
        cin >> a;
        REP(j, s + 1){
            if(dp[i][j] == -1){
                continue;
            }
            if(j + a <= s){
                // 足すとき
                num[i + 1][j + a] += num[i][j];
                chmax(dp[i + 1][j + a], 0LL);
                dp[i + 1][j + a] += dp[i][j] + num[i][j] * (i + 1);
                dp[i + 1][j + a] %= MOD;
            }

            // 足さないとき
            num[i + 1][j] += num[i][j];
            chmax(dp[i + 1][j], 0LL);
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
    }
    cout << (dp[n][s] == -1 ? 0 : dp[n][s]) << endl;
    // REP(i, n + 1){
    //     REP(j, s + 1){
    //         // cout << dp[i][j] << ' ';
    //         printf("%3d ", dp[i][j]);
    //     }
    //     cout << endl;
    // }
}