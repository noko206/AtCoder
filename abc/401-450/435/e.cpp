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
template <typename T>
pair<unordered_map<T, int>, vector<T>> compress(const vector<T>& a) {
    auto decomp = a;
    sort(decomp.begin(), decomp.end());
    decomp.erase(unique(decomp.begin(), decomp.end()), decomp.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)decomp.size(); ++i) {
        comp[decomp[i]] = i;
    }
    return {comp, decomp};
}

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
    int n, q;
    cin >> n >> q;
    vector<int> l(q), r(q);
    unordered_map<int, bool> is_black;
    REP(i, q) {
        cin >> l[i] >> r[i];
        is_black[l[i]] = true;
        is_black[r[i]] = true;
    }
    vector<int> tmp;
    tmp.push_back(1);
    REP(i, q) {
        tmp.push_back(l[i]);
        if (l[i] + 1 <= n) {
            tmp.push_back(l[i] + 1);
        }
        tmp.push_back(r[i]);
        if (r[i] + 1 <= n) {
            tmp.push_back(r[i] + 1);
        }
    }
    auto [comp, decomp] = compress(tmp);

    int m = comp.size();
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(m);
    REP(i, m) {
        if (is_black.find(decomp[i]) == is_black.end()) {
            if (i == m - 1) {
                seg.set(i, {n - decomp[i] + 1, 1});
            } else {
                seg.set(i, {decomp[i + 1] - decomp[i], 1});
            }
        } else {
            seg.set(i, {1, 1});
        }
    }
    vector<ll> ans(q);
    REP(i, q) {
        int lc = comp[l[i]];
        int rc = comp[r[i]];
        seg.apply(lc, rc + 1, 0);
        ans[i] = seg.all_prod().value;
    }
    REP(i, q) output(ans[i]);
}
