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
    int n, m;
    cin >> n >> m;
    vector dp(n + 1, vector<ll>(n + 1, INF64));
    REP(i, n + 1) dp[i][i] = 0;
    REP(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        chmin(dp[a][b], c);
        chmin(dp[b][a], c);
    }
    int k;
    ll t;
    cin >> k >> t;
    vector<int> d(k);
    REP(i, k) cin >> d[i], --d[i];
    REP(i, k) dp[d[i]][n] = 0, dp[n][d[i]] = t;
    REP(mid, n + 1) {
        REP(i, n + 1) {
            REP(j, n + 1) { chmin(dp[i][j], dp[i][mid] + dp[mid][j]); }
        }
    }
    int q;
    cin >> q;
    vector<ll> ans;
    REP(_, q) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y;
            ll z;
            cin >> x >> y >> z;
            --x, --y;
            chmin(dp[x][y], z);
            chmin(dp[y][x], z);
            REP(v, n + 1) {
                REP(u, n + 1) {
                    chmin(dp[v][u], dp[v][x] + dp[x][y] + dp[y][u]);
                    chmin(dp[v][u], dp[v][y] + dp[y][x] + dp[x][u]);
                }
            }
        } else if (tp == 2) {
            int x;
            cin >> x;
            --x;
            chmin(dp[x][n], 0LL);
            chmin(dp[n][x], t);
            REP(v, n + 1) {
                REP(u, n + 1) {
                    chmin(dp[v][u], dp[v][x] + dp[x][n] + dp[n][u]);
                    chmin(dp[v][u], dp[v][n] + dp[n][x] + dp[x][u]);
                }
            }
        } else {
            ll sum = 0;
            REP(x, n) {
                REP(y, n) {
                    if (dp[x][y] != INF64) {
                        sum += dp[x][y];
                    }
                }
            }
            ans.push_back(sum);
        }
    }
    REP(i, ans.size()) output(ans[i]);
}
