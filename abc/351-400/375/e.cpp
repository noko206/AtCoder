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
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i], --a[i];
    vector dp(1501, vector<int>(1501, INF32));
    int sumA = 0, sumB = 0, sum = 0;
    REP(i, n) {
        if (a[i] == 0) {
            sumA += b[i];
        } else if (a[i] == 1) {
            sumB += b[i];
        }
        sum += b[i];
    }
    if (sum % 3 != 0) {
        output(-1);
        return 0;
    }
    dp[sumA][sumB] = 0;
    REP(i, n) {
        auto dp2 = dp;
        REP(x, 1501) {
            REP(y, 1501) {
                if (a[i] == 0) {
                    if (x - b[i] >= 0) {
                        chmin(dp2[x - b[i]][y], dp[x][y] + 1);
                    }
                    if (x - b[i] >= 0 && y + b[i] <= 1500) {
                        chmin(dp2[x - b[i]][y + b[i]], dp[x][y] + 1);
                    }
                } else if (a[i] == 1) {
                    if (y - b[i] >= 0) {
                        chmin(dp2[x][y - b[i]], dp[x][y] + 1);
                    }
                    if (x + b[i] <= 1500 && y - b[i] >= 0) {
                        chmin(dp2[x + b[i]][y - b[i]], dp[x][y] + 1);
                    }
                } else {
                    if (x + b[i] <= 1500) {
                        chmin(dp2[x + b[i]][y], dp[x][y] + 1);
                    }
                    if (y + b[i] <= 1500) {
                        chmin(dp2[x][y + b[i]], dp[x][y] + 1);
                    }
                }
            }
        }
        dp = dp2;
    }
    output(dp[sum / 3][sum / 3] == INF32 ? -1 : dp[sum / 3][sum / 3]);
}
