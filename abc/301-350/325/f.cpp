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
    vector<int> d(n);
    REP(i, n) cin >> d[i];
    vector<int> l(2), c(2), k(2);
    REP(i, 2) cin >> l[i] >> c[i] >> k[i];
    vector dp(n + 1, vector<int>(k[0] + 1, INF32));
    dp[0][0] = 0;
    REP(i, n) {
        REP(j, k[0] + 1) {
            REP(m, k[0] + 1) {
                if (j + m > k[0]) break;
                ll cnt = 0;
                if (m * l[0] < d[i]) {
                    cnt = ((ll)d[i] - m * l[0] + l[1] - 1) / l[1];
                }
                if (dp[i][j] + cnt > k[1]) continue;
                chmin(dp[i + 1][j + m], dp[i][j] + (int)cnt);
            }
        }
    }
    ll ans = INF64;
    REP(i, k[0] + 1) {
        if (dp[n][i] == INF32) continue;
        ll cnt1 = i;
        ll cnt2 = dp[n][i];
        chmin(ans, cnt1 * c[0] + cnt2 * c[1]);
    }
    output(ans == INF64 ? -1 : ans);
}
