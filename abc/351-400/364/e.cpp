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
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    // vector<int> a(n), b(n);
    // REP(i, n) cin >> a[i] >> b[i];
    vector<pair<int, int>> ab(n), ba(n);
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        ab[i] = {a, b};
        ba[i] = {b, a};
    }
    sort(ALL(ab));
    sort(ALL(ba));
    int ans = 0;
    {
        vector dp(x + 2, vector<int>(n + 1, INF32));
        dp[0][0] = 0;
        REP(i, n) {
            auto [a, b] = ab[i];
            RREP(j, x) {
                RREP(k, n) {
                    if (dp[j][k] > y) continue;
                    chmin(dp[min(j + a, x + 1)][k + 1],
                          min(dp[j][k] + b, y + 1));
                }
            }
        }
        REP(i, x + 2) {
            REP(j, n + 1) {
                if (dp[i][j] == INF32) continue;
                chmax(ans, j);
            }
        }
    }
    {
        vector dp(x + 2, vector<int>(n + 1, INF32));
        dp[0][0] = 0;
        REP(i, n) {
            auto [b, a] = ba[i];
            RREP(j, x) {
                RREP(k, n) {
                    if (dp[j][k] > y) continue;
                    chmin(dp[min(j + a, x + 1)][k + 1],
                          min(dp[j][k] + b, y + 1));
                }
            }
        }
        REP(i, x + 2) {
            REP(j, n + 1) {
                if (dp[i][j] == INF32) continue;
                chmax(ans, j);
            }
        }
    }
    output(ans);
}
