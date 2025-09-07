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
struct S {
    long long value;
    int size;
};
using F = long long;

const F ID = 8e18;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
    if (f != ID) x.value = f * x.size;
    return x;
}
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
    int q;
    cin >> q;
    vector<tuple<int, int, int>> query(q);
    vector<int> to(q + 1, -1);
    REP(i, q) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x;
            y = -1;
            to[i + 1] = to[x];
            to[x] = i + 1;
        } else {
            cin >> x >> y;
        }
        query[i] = {t, x, y};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(q + 1);
    int id = 0;
    int pos = 0;
    vector<int> from(q + 1);
    while (pos != -1) {
        S tmp;
        tmp.size = 1;
        tmp.value = pos;
        seg.set(id, tmp);
        from[pos] = id;
        pos = to[pos];
        ++id;
    }
    vector<ll> ans;
    for (auto [t, x, y] : query) {
        if (t == 1) {
            // ...
        } else {
            int l = from[x];
            int r = from[y];
            if (l > r) swap(l, r);
            ans.push_back(seg.prod(l, r).value);
            seg.apply(l, r, 0LL);
        }
    }
    REP(i, ans.size()) output(ans[i]);
}
