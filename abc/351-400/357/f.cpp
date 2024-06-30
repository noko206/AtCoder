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

struct S {
    mint a;
    mint b;
    mint sum;
    int size;
};

S op(S x, S y) { return {x.sum + y.sum, 1, x.sum + y.sum, x.size + y.size}; }

S e() { return {0, 0, 0, 0}; }

struct F {
    mint a;
    mint b;
};

S mapping(F f, S x) {
    mint a = x.a + f.a * x.size;
    mint b = x.b + f.b * x.size;
    return {a, b, a * b, x.size};
}

F composition(F f, F g) { return {f.a + g.a, f.b + g.b}; }

F id() { return {0, 0}; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    REP(i, n) seg.set(i, {a[i], b[i], (mint)a[i] * b[i], 1});
    vector<mint> ans;
    REP(i, q) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 1) {
            int x;
            cin >> x;
            seg.apply(l, r, {x, 0});
        } else if (t == 2) {
            int x;
            cin >> x;
            seg.apply(l, r, {0, x});
        } else {
            S s = seg.prod(l, r);
            ans.push_back(s.sum);
        }
        output("=== start ===");
        REP(i, n) {
            auto tmp = seg.get(i);
            output(tmp.a.val(), tmp.b.val(), tmp.sum.val());
        }
        output("=== end ===");
    }
    REP(i, ans.size()) output(ans[i].val());
}
