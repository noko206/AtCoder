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
ll dp[105][6][6][6][6][6];

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    REP(i, n + 1) {
        REP(a, 6) {
            REP(b, 6) {
                REP(c, 6) {
                    REP(d, 6) {
                        REP(e, 6) { dp[i][a][b][c][d][e] = INF64; }
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0][0] = 0;
    REP(i, n) {
        int cost;
        cin >> cost;
        vector<int> value(k);
        REP(j, k) cin >> value[j];
        REP(a, 6) {
            REP(b, 6) {
                REP(c, 6) {
                    REP(d, 6) {
                        REP(e, 6) {
                            int na = 0, nb = 0, nc = 0, nd = 0, ne = 0;
                            if (k >= 1) na = value[0];
                            if (k >= 2) nb = value[1];
                            if (k >= 3) nc = value[2];
                            if (k >= 4) nd = value[3];
                            if (k >= 5) ne = value[4];
                            chmin(
                                dp[i + 1][min(a + na, p)][min(b + nb, p)][min(
                                    c + nc, p)][min(d + nd, p)][min(e + ne, p)],
                                dp[i][a][b][c][d][e] + cost);
                            chmin(dp[i + 1][a][b][c][d][e],
                                  dp[i][a][b][c][d][e]);
                        }
                    }
                }
            }
        }
    }
    ll ans = INF64;
    REP(a, 6) {
        REP(b, 6) {
            REP(c, 6) {
                REP(d, 6) {
                    REP(e, 6) {
                        if (k >= 1 && a < p) continue;
                        if (k >= 2 && b < p) continue;
                        if (k >= 3 && c < p) continue;
                        if (k >= 4 && d < p) continue;
                        if (k >= 5 && e < p) continue;
                        chmin(ans, dp[n][a][b][c][d][e]);
                    }
                }
            }
        }
    }
    output(ans == INF64 ? -1 : ans);
}
