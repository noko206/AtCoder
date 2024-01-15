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
using mint = modint998244353;

struct F {
    mint a, b;
    F(mint a = 1, mint b = 0) : a(a), b(b) {}
};
mint mapping(F f, mint x) { return f.a * x + f.b; }
F composition(F g, F f) { return F(f.a * g.a, g.b + g.a * f.b); }
F id() { return F(); }
mint op(mint a, mint b) { return 0; }
mint e() { return 0; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n);
    REP(i, n) {
        int _a;
        cin >> _a;
        a[i] = _a;
    }
    lazy_segtree<mint, op, e, F, mapping, composition, id> seg(a);
    REP(i, m) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        mint p = mint(1) / (r - l), q = mint(1) - p;
        seg.apply(l, r, F(q, p * x));
    }
    REP(i, n) output(seg.get(i).val());
}
