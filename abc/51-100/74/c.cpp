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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector dp(f + 1, vector<bool>(f + 1, false));
    dp[0][0] = true;
    double tmp = 0;
    int ansW = 100 * a, ansS = 0;
    REP(i, 1, f + 1) {
        REP(j, i + 1) {
            int water = i - j;
            int sugar = j;
            if (i - 100 * a >= 0 && dp[i - 100 * a][j]) dp[i][j] = true;
            if (i - 100 * b >= 0 && dp[i - 100 * b][j]) dp[i][j] = true;
            if (i - c >= 0 && j - c >= 0 && dp[i - c][j - c]) dp[i][j] = true;
            if (i - d >= 0 && j - d >= 0 && dp[i - d][j - d]) dp[i][j] = true;
            if (sugar * 100 <= water * e && dp[i][j]) {
                double z = 100 * j / (double)i;
                if (chmax(tmp, z)) {
                    ansW = i;
                    ansS = j;
                }
            }
        }
    }
    output(ansW, ansS);
}
