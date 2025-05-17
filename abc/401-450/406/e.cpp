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
using mint = modint998244353;

int f(ll n) {
    int ans = 0;
    while (n > 0) {
        n /= 2;
        ++ans;
    }
    return ans;
}

mint solve() {
    ll n;
    int k;
    cin >> n >> k;
    int pos = f(n);
    mint ans = 0;
    RREP(x, pos, 1) {
        vector dp(pos + 1, vector(k + 1, vector<mint>(2, 0)));
        dp[pos][0][0] = 1;
        RREP(i, pos, 1) {
            REP(j, k + 1) {
                if (n & (1LL << (i - 1))) {
                    // ビットを立てる場合
                    if (j + 1 <= k) {
                        dp[i - 1][j + 1][0] += dp[i][j][0];
                        dp[i - 1][j + 1][1] += dp[i][j][1];
                    }
                    // ビットを立てない場合
                    if (i != x) {
                        dp[i - 1][j][1] += dp[i][j][0];
                        dp[i - 1][j][1] += dp[i][j][1];
                    }
                } else {
                    // ビットを立てる場合
                    if (j + 1 <= k) {
                        // dp[i - 1][j + 1][0] += dp[i][j][0];
                        dp[i - 1][j + 1][1] += dp[i][j][1];
                    }
                    // ビットを立てない場合
                    if (i != x) {
                        dp[i - 1][j][0] += dp[i][j][0];
                        dp[i - 1][j][1] += dp[i][j][1];
                    }
                }
            }
        }
        mint cnt = dp[0][k][0] + dp[0][k][1];
        mint num = 1;
        REP(i, x - 1) { num *= 2; }
        // output(num.val(), " x ", cnt.val());
        ans += cnt * num;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<mint> ans(t);
    REP(i, t) ans[i] = solve();
    REP(i, t) output(ans[i].val());
}
