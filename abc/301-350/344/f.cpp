// clang-format off
#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(int i=int(a);i>=int(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T> T gcd(T x, T y){ return (x % y) ? gcd(y, x % y) : y; }
template<class T> T lcm(T x, T y){ return x / gcd(x, y) * y; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
pair<ll, ll> dp[80][80][80][80];

int main() {
    int n;
    cin >> n;
    vector p(n, vector<int>(n));
    REP(i, n) REP(j, n) cin >> p[i][j];
    vector r(n, vector<int>(n - 1));
    REP(i, n) REP(j, n - 1) cin >> r[i][j];
    vector d(n - 1, vector<int>(n));
    REP(i, n - 1) REP(j, n) cin >> d[i][j];
    REP(i, 80) REP(j, 80) REP(k, 80) REP(l, 80) dp[i][j][k][l] = {0, INF64};
    dp[0][0][0][0] = {0, 0};
    REP(i, n) {
        REP(j, n) {
            REP(pi, n) {
                REP(pj, n) {
                    auto [money, cnt] = dp[i][j][pi][pj];
                    if (cnt == INF64) continue;
                    int maxP = p[pi][pj];
                    // 右に行くとき
                    if (true) {
                        int _pi = pi, _pj = pj;
                        if (maxP < p[i][j + 1]) {
                            _pi = i;
                            _pj = j;
                        }
                        // dp[i][j + 1][_pi][_pj] =
                    }
                    // 下に行くとき
                    if (true) {
                    }
                }
            }
        }
    }
}
