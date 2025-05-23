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
    vector<string> a(n);
    REP(i, n) cin >> a[i];
    vector<string> ans(n, string(n, ' '));
    auto f = [&](int i, int j, int r) -> char {
        switch (r) {
            // 右
            case 0:
                return a[n - 1 - j][i];
            // 下
            case 1:
                return a[n - 1 - i][n - 1 - j];
            // 左
            case 2:
                return a[j][n - 1 - i];
            // 上
            case 3:
                return a[i][j];
        }
        assert(false);
    };
    REP(k, n / 2) {
        REP(i, k, n - k) {
            // 上
            ans[k][i] = f(k, i, k % 4);
            // 右
            ans[i][n - 1 - k] = f(i, n - 1 - k, k % 4);
            // 下
            ans[n - 1 - k][n - 1 - i] = f(n - 1 - k, n - 1 - i, k % 4);
            // 左
            ans[n - 1 - i][k] = f(n - 1 - i, k, k % 4);
        }
    }
    REP(i, n) output(ans[i]);
}
