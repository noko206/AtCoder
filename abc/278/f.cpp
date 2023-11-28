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
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector dp(1 << n, vector<int>(n, -1));  // -1=到達不可,0先手負け,1先手勝ち
    // 初期化
    REP(bit, 1 << n) {
        REP(i, n) {
            if (!(bit & (1 << i))) continue;
            bool is_continue = false;
            char last = s[i][s[i].length() - 1];
            REP(j, n) {
                if (i == j) continue;
                if (bit & (1 << j)) continue;
                if (last == s[j][0]) {
                    is_continue = true;
                }
            }
            if (is_continue) continue;
            if (__builtin_popcount(bit) % 2 == 0) {
                dp[bit][i] = 0;
            } else {
                dp[bit][i] = 1;
            }
        }
    }
    // bitDP
    RREP(bit, (1 << n) - 1) {
        REP(i, n) {
            if (!(bit & (1 << i))) continue;
            if (dp[bit][i] == -1) continue;
            // dp[bit & ~(1 << i)][j] <- dp[bit][i] の遷移
            REP(j, n) {
                if (!(bit & (1 << j))) continue;
                if (s[j][s[j].length() - 1] != s[i][0]) continue;
                if (__builtin_popcount(bit) % 2 == 0) {
                    if (dp[bit & ~(1 << i)][j] == 1 || dp[bit][i] == 1) {
                        dp[bit & ~(1 << i)][j] = 1;
                    } else {
                        dp[bit & ~(1 << i)][j] = 0;
                    }
                } else {
                    if (dp[bit & ~(1 << i)][j] == 0 || dp[bit][i] == 0) {
                        dp[bit & ~(1 << i)][j] = 0;
                    } else {
                        dp[bit & ~(1 << i)][j] = 1;
                    }
                }
            }
        }
    }
    bool win_first = false;
    REP(i, n) {
        if (dp[1 << i][i] == 1) {
            win_first = true;
        }
    }
    output(win_first ? "First" : "Second");
    // REP(i, 1 << n) { output(dp[i]); }
}
