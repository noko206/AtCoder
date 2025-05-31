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
int solve(int n, string s) {
    vector dp(n + 1, vector(2, vector<int>(2, INF32)));
    dp[0][0][0] = 0;
    REP(i, n) {
        if (s[i] == '0') {
            // 0のまま
            chmin(dp[i + 1][0][0], dp[i][0][0]);
            chmin(dp[i + 1][0][1], dp[i][0][1]);
            chmin(dp[i + 1][0][1], dp[i][1][1]);

            // 1に変更
            chmin(dp[i + 1][1][1], dp[i][0][0] + 1);
            chmin(dp[i + 1][1][1], dp[i][1][1] + 1);
        } else {
            // 0に変更
            chmin(dp[i + 1][0][0], dp[i][0][0] + 1);
            chmin(dp[i + 1][0][1], dp[i][0][1] + 1);
            chmin(dp[i + 1][0][1], dp[i][1][1] + 1);

            // 1のまま
            chmin(dp[i + 1][1][1], dp[i][0][0]);
            chmin(dp[i + 1][1][1], dp[i][1][1]);
        }
    }
    int ans = INF32;
    REP(i, 2) REP(j, 2) chmin(ans, dp[n][i][j]);
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<int> ans(t);
    REP(i, t) {
        int n;
        string s;
        cin >> n >> s;
        ans[i] = solve(n, s);
    }
    REP(i, t) output(ans[i]);
}
