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
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> c(n);
    ll sumC = 0;
    REP(i, n) cin >> c[i], sumC += c[i];
    vector<ll> dp(n, -1);
    auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> ll {
        if (dp[v] != -1) return dp[v];
        ll sum = c[v];
        for (int u : to[v]) {
            if (u == p) continue;
            sum += dfs(dfs, u, v);
        }
        return dp[v] = sum;
    };
    dfs(dfs);
    vector<ll> f(n, INF64);
    f[0] = 0;
    auto dfs2 = [&](auto &dfs2, int v = 0, int p = -1, int depth = 0) -> void {
        f[0] += (ll)c[v] * depth;
        for (int u : to[v]) {
            if (u == p) continue;
            dfs2(dfs2, u, v, depth + 1);
        }
    };
    dfs2(dfs2);
    ll ans = INF64;
    auto dfs3 = [&](auto &dfs3, int v = 0, int p = -1) -> void {
        for (int u : to[v]) {
            if (u == p) continue;
            f[u] = f[v] - dp[u] + (sumC - dp[u]);
            dfs3(dfs3, u, v);
        }
    };
    dfs3(dfs3);
    REP(i, n) chmin(ans, f[i]);
    output(ans);
}
