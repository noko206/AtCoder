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
int dp[1005][2][2][2];  // 真ん中、上、下

int main() {
    int h, w;
    cin >> h >> w;
    vector v(h, vector<int>(w));
    REP(i, h) REP(j, w) cin >> v[i][j];
    REP(i, h) REP(a, 2) REP(b, 2) REP(c, 2) dp[i + 1][a][b][c] = INF32;
    REP(i, h) {
        REP(a, 2) {
            bool is_ok = true;
            if (!is_ok) continue;
            REP(b, 2) REP(c, 2) {
                bool is_ok = true;
                REP(j, w) {
                    bool ok = false;
                    if (i - 1 >= 0 &&
                        (v[i][j] + a) % 2 == (v[i - 1][j] + b) % 2)
                        ok = true;
                    if (i + 1 < h && (v[i][j] + a) % 2 == (v[i + 1][j] + c) % 2)
                        ok = true;
                    if (j - 1 >= 0 && v[i][j] == v[i][j - 1]) ok = true;
                    if (j + 1 < w && v[i][j] == v[i][j + 1]) ok = true;
                    if (!ok) {
                        is_ok = false;
                        break;
                    }
                }
                if (!is_ok) continue;
                REP(k, 2) {
                    chmin(dp[i + 1][a][b][c], dp[i][b][k][a] + a);
                    // if (i == 1 && dp[i][b][k][a] + a == 0) {
                    //     output(i, a, b, c, k);
                    // }
                }
            }
        }
    }
    int ans = INF32;
    REP(i, 2) REP(j, 2) REP(k, 2) chmin(ans, dp[h][i][j][k]);
    output(ans == INF32 ? -1 : ans);
    // REP(i, h + 1) REP(a, 2) REP(b, 2) REP(c, 2) {
    //     output(i, a, b, c, dp[i][a][b][c]);
    // }
}
