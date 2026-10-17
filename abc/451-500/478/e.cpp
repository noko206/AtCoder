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
    scc_graph g(n);
    vector<vector<pair<int, int>>> to(n);
    REP(i, q) {
        int t, u, v;
        cin >> t >> u >> v;
        --u, --v;
        to[u].emplace_back(v, t);
        g.add_edge(u, v);
    }
    auto scc = g.scc();
    vector<int> dp(n);
    int id = 1;
    for (auto v : scc) {
        for (int x : v) {
            dp[x] = id;
            ++id;
        }
    }
    bool is_ok = true;
    vector<bool> visited(n, false);
    auto dfs = [&](auto& dfs, int v) -> void {
        if (visited[v]) return;
        visited[v] = true;
        for (auto [u, t] : to[v]) {
            if (t == 0) {
                if (dp[v] > dp[u]) is_ok = false;
                dfs(dfs, u);
            } else {
                if (dp[v] >= dp[u]) is_ok = false;
                dfs(dfs, u);
            }
        }
    };
    REP(i, n) dfs(dfs, i);
    if (is_ok) {
        output("Yes");
        output(dp);
    } else {
        output("No");
        output(dp);
    }
}
