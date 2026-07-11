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
mint dp[501][3][2][1024][2];

int main() {
    string n;
    cin >> n;
    dp[0][0][0][0][0] = 1;
    int N = n.length();
    REP(i, N) {
        int ni = n[i] - '0';
        REP(a, 3) REP(b, 2) REP(c, 1024) {
            REP(k, 10) {
                int na = (a + k) % 3;
                int nb = b == 1 ? 1 : (k == 3 ? 1 : 0);
                int nc = c | (1 << k);
                if (c == 0 && k == 0) nc = 0;
                dp[i + 1][na][nb][nc][1] += dp[i][a][b][c][1];
            }

            REP(k, ni) {
                int na = (a + k) % 3;
                int nb = b == 1 ? 1 : (k == 3 ? 1 : 0);
                int nc = c | (1 << k);
                if (c == 0 && k == 0) nc = 0;
                dp[i + 1][na][nb][nc][1] += dp[i][a][b][c][0];
            }

            {
                int na = (a + ni) % 3;
                int nb = b == 1 ? 1 : (ni == 3 ? 1 : 0);
                int nc = c | (1 << ni);
                if (c == 0 && ni == 0) nc = 0;
                dp[i + 1][na][nb][nc][0] += dp[i][a][b][c][0];
            }
        }
    }
    mint ans = 0;
    REP(a, 3) REP(b, 2) REP(c, 1024) {
        int cnt = 0;
        if (a == 0) cnt++;
        if (b == 1) cnt++;
        if (__builtin_popcount(c) == 3) cnt++;
        if (cnt != 1) continue;
        ans += dp[N][a][b][c][0] + dp[N][a][b][c][1];
    }
    ans -= 1;
    output(ans.val());
}
