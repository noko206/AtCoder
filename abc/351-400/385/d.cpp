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
    int n, m;
    ll sx, sy;
    cin >> n >> m >> sx >> sy;
    map<ll, set<ll>> x_to_y, y_to_x;
    REP(i, n) {
        ll x, y;
        cin >> x >> y;
        x_to_y[x].insert(y);
        y_to_x[y].insert(x);
    }
    int ans = 0;
    REP(i, m) {
        char d;
        ll c;
        cin >> d >> c;
        if (d == 'U') {
            if (x_to_y.find(sx) != x_to_y.end()) {
                while (true) {
                    auto it = x_to_y[sx].lower_bound(sy);
                    if (it == x_to_y[sx].end() || *it > sy + c) break;
                    y_to_x[*it].erase(sx);
                    x_to_y[sx].erase(it);
                    ++ans;
                }
            }
            sy += c;
        } else if (d == 'D') {
            if (x_to_y.find(sx) != x_to_y.end()) {
                while (true) {
                    auto it = x_to_y[sx].lower_bound(sy - c);
                    if (it == x_to_y[sx].end() || *it > sy) break;
                    y_to_x[*it].erase(sx);
                    x_to_y[sx].erase(it);
                    ++ans;
                }
            }
            sy -= c;
        } else if (d == 'L') {
            if (y_to_x.find(sy) != y_to_x.end()) {
                while (true) {
                    auto it = y_to_x[sy].lower_bound(sx - c);
                    if (it == y_to_x[sy].end() || *it > sx) break;
                    x_to_y[*it].erase(sy);
                    y_to_x[sy].erase(*it);
                    ++ans;
                }
            }
            sx -= c;
        } else {
            if (y_to_x.find(sy) != y_to_x.end()) {
                while (true) {
                    auto it = y_to_x[sy].lower_bound(sx);
                    if (it == y_to_x[sy].end() || *it > sx + c) break;
                    x_to_y[*it].erase(sy);
                    y_to_x[sy].erase(it);
                    ++ans;
                }
            }
            sx += c;
        }
    }
    output(sx, sy, ans);
}
