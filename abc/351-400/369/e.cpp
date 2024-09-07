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
using P = pair<ll, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> to(n);
    vector<tuple<int, int, int>> edge(m);
    REP(i, m) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        to[u].emplace_back(v, t);
        to[v].emplace_back(u, t);
        edge[i] = {u, v, t};
    }
    // 前処理
    vector dist(n, vector<ll>(n, INF64));
    REP(i, n) dist[i][i] = 0;
    REP(s, n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({s, 0});
        while (!pq.empty()) {
            auto [v, vc] = pq.top();
            pq.pop();
            if (dist[s][v] < vc) continue;
            for (auto [u, uc] : to[v]) {
                if (chmin(dist[s][u], dist[s][v] + uc)) {
                    pq.push({u, dist[s][u]});
                }
            }
        }
    }
    // クエリ処理
    int q;
    cin >> q;
    vector<ll> ans(q);
    REP(i, q) {
        int k;
        cin >> k;
        vector<int> b(k);
        REP(j, k) cin >> b[j], --b[j];
        ll minCost = INF64;
        do {
            vector dp(k, vector<ll>(2, INF64));
            // 最初
            {
                auto [v, u, t] = edge[b[0]];
                dp[0][0] = dist[0][u] + t;
                dp[0][1] = dist[0][v] + t;
            }
            // 中間
            REP(j, k - 1) {
                auto [sv, su, st] = edge[b[j]];
                auto [gv, gu, gt] = edge[b[j + 1]];
                dp[j + 1][0] = min(dp[j][0] + dist[sv][gu] + gt,
                                   dp[j][1] + dist[su][gu] + gt);
                dp[j + 1][1] = min(dp[j][0] + dist[sv][gv] + gt,
                                   dp[j][1] + dist[su][gv] + gt);
            }
            // 最後
            {
                auto [v, u, t] = edge[b[k - 1]];
                ll cost = min(dp[k - 1][0] + dist[v][n - 1],
                              dp[k - 1][1] + dist[u][n - 1]);
                chmin(minCost, cost);
            }
        } while (next_permutation(ALL(b)));
        ans[i] = minCost;
    }
    REP(i, q) output(ans[i]);
}
