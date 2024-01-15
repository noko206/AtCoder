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
using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> s(2);
    REP(i, 2) cin >> s[i];
    vector dp(n + 1, vector<vector<mint>>(4, vector<mint>(4, 0)));
    dp[0][0][0] = 1;
    vector<int> cnt(n, -1);
    REP(i, n) {
        if (s[0][i] == s[1][i]) {
            cnt[i] = 1;
        } else {
            cnt[i + 1] = 2;
            ++i;
        }
    }
    REP(i, n) {
        if (cnt[i] == -1) continue;
        if (cnt[i] == 1) {
            REP(a, 4) {
                REP(b, 4) {
                    set<int> st;
                    if (a > 0) st.insert(a);
                    if (b > 0) st.insert(b);
                    REP(c, 1, 4) {
                        if (st.find(c) == st.end()) {
                            dp[i + 1][c][0] += dp[i][a][b];
                        }
                    }
                }
            }
        } else {
            if (i == 1) {
                REP(a, 1, 4) {
                    REP(b, 1, 4) {
                        if (a == b) continue;
                        ++dp[i + 1][a][b];
                    }
                }
            } else {
                if (cnt[i - 2] == 1) {
                    REP(a, 1, 4) {
                        REP(c, 1, 4) {
                            REP(d, 1, 4) {
                                if (a != c && c != d && d != a) {
                                    dp[i + 1][c][d] += dp[i - 1][a][0];
                                }
                            }
                        }
                    }
                } else {
                    REP(a, 1, 4) {
                        REP(b, 1, 4) {
                            REP(c, 1, 4) {
                                REP(d, 1, 4) {
                                    if (a != c && b != d && a != b && c != d) {
                                        dp[i + 1][c][d] += dp[i - 1][a][b];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    mint ans = 0;
    REP(a, 4) {
        REP(b, 4) { ans += dp[n][a][b]; }
    }
    output(ans.val());
    // REP(i, n + 1) {
    //     mint sum = 0;
    //     REP(a, 4) {
    //         REP(b, 4) { sum += dp[i][a][b]; }
    //     }
    //     cout << sum.val() << ' ';
    // }
    // cout << endl;
}
