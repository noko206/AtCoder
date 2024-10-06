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
    ll x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    REP(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    int ok = 0;
    int ng = INF32;
    int border = 1000;  // 書き換え可能
    while (ng - ok != 1) {
        int mid = (ok + ng) / 2;
        ll tot = x;
        REP(i, n) {
            ll cost = INF64;
            // sを購入した個数を基準に探索
            ll maxS = (mid + a[i] - 1) / a[i];
            chmin(cost, maxS * p[i]);
            for (ll s = maxS - 1; s >= max(maxS - border, 0LL); --s) {
                ll t = (mid - s * a[i] + b[i] - 1) / b[i];
                chmin(cost, s * p[i] + t * q[i]);
            }
            // tを購入した個数を基準に探索
            ll maxT = (mid + b[i] - 1) / b[i];
            chmin(cost, maxT * q[i]);
            for (ll t = maxT - 1; t >= max(maxT - border, 0LL); --t) {
                ll s = (mid - t * b[i] + a[i] - 1) / a[i];
                chmin(cost, s * p[i] + t * q[i]);
            }
            tot -= cost;
            if (tot < 0) break;
        }
        if (tot >= 0) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    output(ok);
}
