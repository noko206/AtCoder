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

int main() {
    int n;
    cin >> n;
    vector dp(n * 2, vector<mint>(n + 1, 0));
    dp[0][n] = 1;
    REP(i, n * 2 - 1) {
        RREP(j, n, 2) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j - 1] += dp[i][j];
        }
    }
    mint inv2 = inv_mod(2, 998244353);
    mint inv_now = 1;
    REP(i, n) inv_now *= inv2;
    mint inv_diff = inv_now;
    mint powN = pow_mod(2, n, 998244353);
    mint hi = powN / (powN - 1);
    vector<int> ans(n);
    REP(i, n - 1) {
        mint tmp = dp[n + i][1];
        tmp *= inv_now;
        tmp *= hi;
        ans[i] = tmp.val();
        inv_now *= inv_diff;
    }
    inv_now = 1;
    REP(i, n - 1) inv_now *= inv2;
    mint tmp = dp[n - 1][1] * inv_now * hi;
    ans[n - 1] = tmp.val();
    output(ans);
}
