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
    vector<vector<pair<int, int>>> to(n);
    vector<int> a(n - 1), b(n - 1);
    REP(i, n - 1) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        to[a[i]].emplace_back(b[i], i);
        to[b[i]].emplace_back(a[i], i);
    }
    vector<pair<int, int>> from_to(n - 1);
    auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
        for (auto [u, e] : to[v]) {
            if (u == p) continue;
            from_to[e] = {v, u};
            dfs(dfs, u, v);
        }
    };
    dfs(dfs);
    int q;
    cin >> q;
    vector<ll> ans(n, 0);
    REP(i, q) {
        int t, e, x;
        cin >> t >> e >> x;
        --e;
        auto [na, nb] = from_to[e];
        if (t == 1) {
            if (na == a[e]) {
                ans[0] += x;
                ans[nb] -= x;
            } else {
                ans[nb] += x;
            }
        } else {
            if (na == b[e]) {
                ans[0] += x;
                ans[nb] -= x;
            } else {
                ans[nb] += x;
            }
        }
    }
    auto dfs2 = [&](auto &dfs2, int v = 0, int p = -1) -> void {
        for (auto [u, e] : to[v]) {
            if (u == p) continue;
            ans[u] += ans[v];
            dfs2(dfs2, u, v);
        }
    };
    dfs2(dfs2);
    REP(i, n) output(ans[i]);
}
