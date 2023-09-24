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
ll naive(ll n, ll x, ll k) {
    vector<vector<int>> to(n + 1);
    REP(i, 1, n + 1) {
        if (i * 2 <= n) {
            to[i].push_back(i * 2);
            to[i * 2].push_back(i);
        }
        if (i * 2 + 1 <= n) {
            to[i].push_back(i * 2 + 1);
            to[i * 2 + 1].push_back(i);
        }
    }
    vector<int> dist(n + 1, 0);
    auto dfs = [&](auto &dfs, int v, int p = -1) -> void {
        for (int u : to[v]) {
            if (u == p) continue;
            dist[u] = dist[v] + 1;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, x);
    int ans = 0;
    REP(i, 1, n + 1) {
        if (dist[i] == k) ++ans;
    }
    return ans;
}

ll solve() {
    ll n, x, k;
    cin >> n >> x >> k;
    auto dfs = [&](auto &dfs, ll v, ll d, ll p = -1) -> ll {
        if (v == 0) return 0;
        if (d == 0) return 1;
        ll ans = 0;
        ans += dfs(dfs, v / 2, d - 1, v);
        ll l = (v * 2 == p) ? (v * 2 + 1) : (v * 2);
        ll r = (v * 2 == p) ? (v * 2 + 1) : (v * 2);
        if (l > n) return ans;
        if (p == -1)
            l = v, r = v;
        else
            --d;
        REP(i, d) {
            l *= 2;
            r *= 2, ++r;
            if (l > n) return ans;
            if (r > n) r = n;
        }
        ans += r - l + 1;
        return ans;
    };
    return dfs(dfs, x, k);
}

int main() {
    int t;
    cin >> t;
    vector<ll> ans(t);
    REP(i, t) { ans[i] = solve(); }
    REP(i, t) { output(ans[i]); }
    // REP(n, 100) {
    //     REP(x, 1, n + 1) {
    //         REP(k, n) {
    //             int solve_ans = solve(n, x, k);
    //             int naive_ans = naive(n, x, k);
    //             if (solve_ans != naive_ans) {
    //                 output(n, x, k, ':', solve_ans, naive_ans);
    //             }
    //         }
    //     }
    // }
}
