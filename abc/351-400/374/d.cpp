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
    double s, t;
    cin >> n >> s >> t;
    vector<int> a(n), b(n), c(n), d(n);
    REP(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    double ans = (double)INF32;
    vector<int> p(n);
    REP(i, n) p[i] = i;
    auto dfs = [&](auto &dfs, int x = 0, int y = 0, int next = 0,
                   double sum = 0) -> void {
        if (next == n) {
            chmin(ans, sum);
            return;
        }
        int i = p[next];
        // (a,b) -> (c,d)
        {
            double tmp = 0;
            tmp += sqrt((x - a[i]) * (x - a[i]) + (y - b[i]) * (y - b[i])) / s;
            tmp += sqrt((a[i] - c[i]) * (a[i] - c[i]) +
                        (b[i] - d[i]) * (b[i] - d[i])) /
                   t;
            dfs(dfs, c[i], d[i], next + 1, sum + tmp);
        }
        // (c,d) -> (a,b)
        {
            double tmp = 0;
            tmp += sqrt((x - c[i]) * (x - c[i]) + (y - d[i]) * (y - d[i])) / s;
            tmp += sqrt((a[i] - c[i]) * (a[i] - c[i]) +
                        (b[i] - d[i]) * (b[i] - d[i])) /
                   t;
            dfs(dfs, a[i], b[i], next + 1, sum + tmp);
        }
    };
    do {
        dfs(dfs);
    } while (next_permutation(ALL(p)));
    output(ans);
}
