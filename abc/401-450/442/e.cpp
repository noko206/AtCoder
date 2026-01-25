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
using T = tuple<int, ll, ll, int>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    map<pair<ll, ll>, int> mp;
    REP(i, n) {
        if (x[i] == 0) {
            if (y[i] > 0) {
                y[i] = 1;
            } else {
                y[i] = -1;
            }
        } else if (y[i] == 0) {
            if (x[i] > 0) {
                x[i] = 1;
            } else {
                x[i] = -1;
            }
        } else {
            int g = gcd(abs(x[i]), abs(y[i]));
            x[i] /= g;
            y[i] /= g;
        }
        mp[{x[i], y[i]}]++;
    }
    vector<T> vec;
    for (auto [p, cnt] : mp) {
        auto [a, b] = p;
        int t;
        if (a < 0 && b < 0) {
            t = 1;
        } else if (a < 0 && b >= 0) {
            t = 1;
        } else if (a >= 0 && b >= 0) {
            t = 2;
        } else {
            t = 2;
        }
        vec.push_back({t, a, b, cnt});
    }
    sort(ALL(vec), [&](const T& a, const T& b) -> bool {
        auto [ta, xa, ya, cnta] = a;
        auto [tb, xb, yb, cntb] = b;
        if (ta != tb) return ta < tb;
        bool flip = (xb < 0 && xa >= 0) || (xb >= 0 && xa < 0);
        if (ta == 1 || true) {
            return flip ? ya * xb < yb * xa : ya * xb > yb * xa;
        } else {
            return flip ? ya * xb > yb * xa : ya * xb < yb * xa;
        }
    });
    int m = vec.size();
    REP(i, m) vec.push_back(vec[i]);
    map<tuple<int, ll, ll>, int> pos;
    REP(i, m) {
        auto [t, a, b, _] = vec[i];
        pos[{t, a, b}] = i;
    }
    fenwick_tree<ll> ft(m * 2);
    REP(i, m) {
        auto [a, b, c, cnt] = vec[i];
        ft.add(i, cnt);
        ft.add(i + m, cnt);
    }
    vector<int> ans(q);
    REP(i, q) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int ta, tb;
        if (x[a] < 0 && y[a] < 0) {
            ta = 1;
        } else if (x[a] < 0 && y[a] >= 0) {
            ta = 1;
        } else if (x[a] >= 0 && y[a] >= 0) {
            ta = 2;
        } else {
            ta = 2;
        }
        if (x[b] < 0 && y[b] < 0) {
            tb = 1;
        } else if (x[b] < 0 && y[b] >= 0) {
            tb = 1;
        } else if (x[b] >= 0 && y[b] >= 0) {
            tb = 2;
        } else {
            tb = 2;
        }
        int ia = pos[{ta, x[a], y[a]}];
        int ib = pos[{tb, x[b], y[b]}];
        if (ib < ia) {
            ib += m;
        }
        ans[i] = ft.sum(ia, ib + 1);
    }
    REP(i, q) output(ans[i]);
    // for (auto [t, a, b, cnt] : vec) {
    //     output(t, a, b, cnt);
    // }
}
