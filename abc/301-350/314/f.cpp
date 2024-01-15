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

int main() {
    int n;
    cin >> n;
    dsu uf(n);
    vector<vector<int>> to(2 * n - 1);
    vector<int> root(n);
    vector<int> size(2 * n - 1, 1);
    REP(i, n) root[i] = i;
    int id = n;
    REP(i, n - 1) {
        int p, q;
        cin >> p >> q;
        --p, --q;
        int v = root[uf.leader(p)];
        int u = root[uf.leader(q)];
        to[id].push_back(v);
        to[id].push_back(u);
        uf.merge(p, q);
        root[uf.leader(p)] = id;
        size[id] = size[v] + size[u];
        ++id;
    }
    vector<mint> dp(2 * n - 1, 0);
    auto dfs = [&](auto &dfs, int p) -> void {
        if (to[p].size() == 0) return;
        assert(to[p].size() == 2);
        int v = to[p][0];
        int u = to[p][1];
        dp[v] = size[v] * inv_mod(size[v] + size[u], 998244353) + dp[p];
        dp[u] = size[u] * inv_mod(size[v] + size[u], 998244353) + dp[p];
        dfs(dfs, v);
        dfs(dfs, u);
    };
    dfs(dfs, 2 * n - 2);
    REP(i, n) output(dp[i].val());
}
