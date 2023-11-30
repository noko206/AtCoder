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
    cin >> n;
    vector<vector<int>> to(n);
    REP(i, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    scc_graph g(n);
    {
        vector<bool> visited(n, false);
        auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
            visited[v] = true;
            for (int u : to[v]) {
                if (u == p) continue;
                g.add_edge(v, u);
                if (!visited[u]) {
                    dfs(dfs, u, v);
                }
            }
        };
        dfs(dfs);
    }
    map<int, bool> mp;
    for (auto v : g.scc()) {
        if (v.size() == 1) continue;
        for (int u : v) {
            mp[u] = true;
        }
    }
    dsu uf(n);
    {
        vector<bool> visited(n, false);
        auto dfs = [&](auto &dfs, int v) -> void {
            visited[v] = true;
            for (int u : to[v]) {
                if (visited[u]) continue;
                if (mp.find(u) != mp.end() && mp.find(v) != mp.end()) continue;
                if (!uf.same(v, u)) {
                    uf.merge(v, u);
                }
                dfs(dfs, u);
            }
        };
        REP(v, n) {
            if (mp.find(v) != mp.end()) continue;
            dfs(dfs, v);
        }
    }
    int q;
    cin >> q;
    vector<bool> ans(q);
    REP(i, q) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        ans[i] = uf.same(x, y);
    }
    REP(i, q) output(ans[i] ? "Yes" : "No");
}
