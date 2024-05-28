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
template <typename T> unordered_map<T, int> compress(vector<T> &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)a.size(); ++i) {
        comp[a[i]] = i;
    }
    return comp;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> txy(q);
    vector<ll> decomp;
    decomp.push_back(0);
    REP(i, q) {
        int t, x, y;
        cin >> t >> x >> y;
        txy[i] = {t, x, y};
        decomp.push_back(y);
    }
    auto comp = compress(decomp);
    fenwick_tree<ll> va(comp.size()), vb(comp.size());
    fenwick_tree<ll> ca(comp.size()), cb(comp.size());
    ca.add(0, n);
    cb.add(0, m);
    vector<int> a(n, 0), b(m, 0);
    ll sum = 0;
    vector<ll> ans;
    for (auto [t, x, y] : txy) {
        --x;
        if (t == 1) {
            int ax = a[x];
            if (ax < comp[y]) {
                sum -= vb.sum(ax, comp[y]);
                sum -= decomp[ax] * cb.sum(0, ax);
                sum += y * cb.sum(0, comp[y]);
            }
            if (comp[y] < ax) {
                sum += vb.sum(comp[y] + 1, ax + 1);
                sum -= decomp[ax] * cb.sum(0, ax + 1);
                sum += y * cb.sum(0, comp[y] + 1);
            }
            va.add(ax, -decomp[ax]);
            va.add(comp[y], y);
            ca.add(ax, -1);
            ca.add(comp[y], 1);
            a[x] = comp[y];
        } else {
            int bx = b[x];
            if (bx < comp[y]) {
                sum -= va.sum(bx, comp[y]);
                sum -= decomp[bx] * ca.sum(0, bx);
                sum += y * ca.sum(0, comp[y]);
            }
            if (comp[y] < bx) {
                sum += va.sum(comp[y] + 1, bx + 1);
                sum -= decomp[bx] * ca.sum(0, bx + 1);
                sum += y * ca.sum(0, comp[y] + 1);
            }
            vb.add(bx, -decomp[bx]);
            vb.add(comp[y], y);
            cb.add(bx, -1);
            cb.add(comp[y], 1);
            b[x] = comp[y];
        }
        ans.push_back(sum);
    }
    REP(i, ans.size()) output(ans[i]);
}
