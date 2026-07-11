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
    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<P>> to(n);
    REP(i, m) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        to[u].emplace_back(t, v);
        to[v].emplace_back(t, u);
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    vector<ll> dp(n, INF64);
    dp[0] = 0;
    while (!pq.empty()) {
        auto [cv, v] = pq.top();
        pq.pop();
        if (dp[v] < cv) continue;
        for (auto [cu, u] : to[v]) {
            if (chmin(dp[u], dp[v] + cu)) {
                pq.push({dp[u], u});
            }
        }
    }
    vector<int> x(n);
    REP(i, n) cin >> x[i];
    vector<pair<ll, int>> z(n);
    REP(i, n) z[i] = {x[i] + dp[i], i};
    sort(ALL(z));
    REP(i, n) {
        ll cz;
        if (z[0].second == i) {
            cz = z[1].first;
        } else {
            cz = z[0].first;
        }
        chmin(dp[i], cz + x[i] + y);
    }
    // 多始点ダイクストラをする
    REP(i, n) {
        pq.push({dp[i], i});
        dp[i] = INF64;
    }
    while (!pq.empty()) {
        auto [cv, v] = pq.top();
        pq.pop();
        chmin(dp[v], cv);
        if (dp[v] < cv) continue;
        for (auto [cu, u] : to[v]) {
            if (chmin(dp[u], dp[v] + cu)) {
                pq.push({dp[u], u});
            }
        }
    }
    vector<ll> ans;
    REP(i, 1, n) ans.push_back(dp[i]);
    output(ans);
}
