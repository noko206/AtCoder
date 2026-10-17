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
    ll k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<ll> a(n), b(m);
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    vector<pair<ll, int>> p;
    REP(i, n) p.emplace_back(a[i], 0);
    REP(i, m) p.emplace_back(b[i], 1);
    sort(ALL(p));
    int ok = 0;
    int ng = n + m + 1;
    while (ng - ok != 1) {
        int mid = (ok + ng) / 2;
        int cnt = 0;
        ll x_ = x, y_ = y;
        int idx = 0;
        for (auto [value, type] : p) {
            ++idx;
            if (type == 1) {
                ll maisu = (value + k - 1) / k;
                if (y_ - maisu < 0) continue;
                y_ -= maisu;
                x_ += maisu * k - value;  // おつり
            }
            ++cnt;
            if (cnt == mid) break;
        }
        if (cnt != mid) {
            ng = mid;
            continue;
        }
        x_ += y_ * k;
        REP(i, idx) {
            auto [value, type] = p[i];
            if (type == 1) continue;
            x_ -= value;
        }
        if (x_ >= 0) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    output(ok);
}
