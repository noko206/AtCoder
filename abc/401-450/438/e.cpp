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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    REP(i, n) cin >> a[i], --a[i];
    vector<bool> is_path(n);
    {
        scc_graph g(n);
        REP(i, n) g.add_edge(i, a[i]);
        dsu uf(n);
        for (auto v : g.scc()) {
            int r = v[0];
            for (auto x : v) {
                if (uf.same(r, x)) continue;
                uf.merge(r, x);
            }
        }
        REP(i, n) { is_path[i] = uf.size(i) == 1 && i != a[i]; }
    }
    vector<bool> is_leaf(n, false);
    {
        vector<vector<int>> to(n);
        REP(i, n) { to[a[i]].push_back(i); }
        REP(i, n) {
            if (to[i].size() == 0) {
                is_leaf[i] = true;
            }
        }
    }
    vector<int> root(n, -1);
    vector<int> pos(n);        // 1-indexed(累積和なので)
    vector<int> last(n, -1);   // 添え字はルート
    map<int, vector<ll>> tot;  // 添え字はルート, 中身は累積和
    auto dfs_path = [&](auto& dfs, int v, int r, int id = 0,
                        int l = -1) -> void {
        if (!is_path[v]) {
            last[r] = l;
            return;
        }
        if (v == r) {
            tot[r].push_back(0);
        }
        root[v] = r;
        pos[v] = id;
        ll sum = tot[r][tot[r].size() - 1];
        tot[r].push_back(sum + v + 1);
        dfs(dfs, a[v], r, id + 1, v);
    };
    auto dfs_loop = [&](auto& dfs, int v, int r = -1, int id = 0) -> void {
        if (root[v] != -1) {
            return;
        }
        if (r == -1) {
            r = v;
            tot[r].push_back(0);
        }
        root[v] = r;
        pos[v] = id;
        ll sum = tot[r][tot[r].size() - 1];
        tot[r].push_back(sum + v + 1);
        dfs(dfs, a[v], r, id + 1);
    };
    REP(v, n) {
        if (is_path[v]) {
            if (is_leaf[v]) {
                dfs_path(dfs_path, v, v);
            }
        } else {
            dfs_loop(dfs_loop, v);
        }
    }
    // クエリ
    vector<ll> ans(q);
    REP(i, q) {
        int t, b;
        cin >> t >> b;
        --b;
        int r = root[b];
        ll sum = 0;
        if (is_path[b]) {
            assert(is_leaf[r]);
            int id = pos[b];
            int len = tot[r].size() - 1;
            int range = len - id;
            sum += tot[r][id + min(t, range)] - tot[r][id];
            t -= range;
            b = a[last[r]];
            r = root[b];
            if (t <= 0) {
                ans[i] = sum;
                continue;
            }
        }
        int id = pos[b];
        int len = tot[r].size() - 1;
        assert(len != 0);
        int cnt = t / len;
        t %= len;
        sum += (ll)cnt * tot[r][len];
        int range = len - id;
        sum += tot[r][id + min(t, range)] - tot[r][id];
        t -= range;
        if (t <= 0) {
            ans[i] = sum;
            continue;
        }
        sum += tot[r][t];
        ans[i] = sum;
    }
    REP(i, q) output(ans[i]);
}
