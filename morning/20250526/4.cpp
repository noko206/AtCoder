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
const char to[] = {'A', 'B', 'X', 'Y'};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INF32;
    REP(a, 4) REP(b, 4) REP(c, 4) REP(d, 4) {
        string l = {to[a], to[b]};
        string r = {to[c], to[d]};
        vector<int> dp(n + 1, INF32);
        dp[0] = 0;
        REP(i, n) {
            chmin(dp[i + 1], dp[i] + 1);
            if (i - 1 >= 0 && s[i - 1] == l[0] && s[i] == l[1]) {
                chmin(dp[i + 1], dp[i - 1] + 1);
            }
            if (i - 1 >= 0 && s[i - 1] == r[0] && s[i] == r[1]) {
                chmin(dp[i + 1], dp[i - 1] + 1);
            }
        }
        chmin(ans, dp[n]);
    }
    output(ans);
}
