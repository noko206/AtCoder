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
    vector<ll> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    std::mt19937 gen(42);
    REP(_, 50) {
        uniform_int_distribution<> dis(0, n - 1);
        int k = dis(gen);
        ll x1 = x[k];
        ll y1 = y[k];
        map<tuple<ll, ll, bool>, int> mp;
        REP(i, n) {
            if (i == k) continue;
            ll x2 = x[i];
            ll y2 = y[i];
            ll dx = x2 - x1;
            ll dy = y2 - y1;
            if (dx != 0 && dy != 0) {
                ll g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
            } else if (dx == 0) {
                if (dy >= 0) {
                    dy = INF64;
                } else {
                    dy = -INF64;
                }
            } else if (dy == 0) {
                if (dx >= 0) {
                    dx = INF64;
                } else {
                    dx = -INF64;
                }
            }
            bool is_plus = false;
            if ((dx >= 0 && dy >= 0) || (dx < 0 && dy < 0)) {
                is_plus = true;
            }
            ++mp[{dx, dy, is_plus}];
        }
        for (auto [t, cnt] : mp) {
            if (cnt >= n / 2) {
                auto [dx, dy, is_plus] = t;
                ll ansX, ansY, ansC;
                if (is_plus) {
                    ansX = dy;
                    ansY = -dx;
                    ansC = dx * y1 - dy * x1;
                } else {
                    ansX = dy;
                    ansY = dx;
                    ansC = -dx * y1 - dy * x1;
                }
                output("Yes");
                output(ansX, ansY, ansC);
                return 0;
            }
        }
    }
    output("No");
}
