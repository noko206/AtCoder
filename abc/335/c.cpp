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
    int n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> d;  // x, y
    d.emplace_back(0, 0);
    vector<pair<ll, ll>> ans;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            auto [dx, dy] = d.back();
            if (c == 'R') {
                ++dx;
            } else if (c == 'L') {
                --dx;
            } else if (c == 'U') {
                ++dy;
            } else {
                --dy;
            }
            d.emplace_back(dx, dy);
        } else {
            int p;
            cin >> p;
            ll nx = p, ny = 0;
            int m = d.size();
            nx -= min(p - 1, m - 1);
            m -= p;
            if (m >= 0) {
                auto [dx, dy] = d[m];
                nx += dx;
                ny += dy;
            }
            ans.emplace_back(nx, ny);
        }
    }
    for (auto [x, y] : ans) output(x, y);
}
