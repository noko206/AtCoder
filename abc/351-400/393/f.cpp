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
pair<unordered_map<T, int>, vector<T>> compress(const vector<T> &a) {
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

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<pair<int, int>> rx(q);
    REP(i, q) {
        int r, x;
        cin >> r >> x;
        rx[i] = {r, x};
    }
    // 座圧
    vector<int> b;
    REP(i, n) b.push_back(a[i]);
    REP(i, q) b.push_back(rx[i].second);
    auto [comp, decomp] = compress(b);
    REP(i, n) a[i] = comp[a[i]];
    REP(i, q) rx[i].second = comp[rx[i].second];
    // 区間変更, 区間最小値取得
    vector<S> v(N + 1, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    // 前処理
    vector<pair<int, int>> x_to_ri(decomp.size());
    REP(i, q) x_to_ri[rx[i].second] = {rx[i].first, i};
    vector<vector<int>> a_to_i(decomp.size());
    REP(i, n) a_to_i[a[i]].push_back(i);
    // メイン処理
    vector<int> ans(q);
    REP(x, decomp.size()) {
        for (auto i : a_to_i[x]) {
            if (seg.get(i + 1).value >= seg.get(i).value) {
                continue;
            }
            seg.max_right<>(i + 1);
        }
    }
}
