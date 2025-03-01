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
using T = tuple<ll, int, bool>;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> to(n), from(n);
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        from[v].push_back(u);
    }
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 0, false});
    vector dist(n, vector<ll>(2, INF64));
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto [dv, v, is_reversed] = pq.top();
        pq.pop();
        if (dist[v][is_reversed] < dv) {
            continue;
        }
        // 移動する場合
        if (is_reversed) {
            for (int u : from[v]) {
                if (chmin(dist[u][1], dv + 1)) {
                    pq.push({dist[u][1], u, true});
                }
            }
        } else {
            for (int u : to[v]) {
                if (chmin(dist[u][0], dv + 1)) {
                    pq.push({dist[u][0], u, false});
                }
            }
        }
        // 反転する場合
        if (is_reversed) {
            if (chmin(dist[v][0], dv + x)) {
                pq.push({dist[v][0], v, false});
            }
        } else {
            if (chmin(dist[v][1], dv + x)) {
                pq.push({dist[v][1], v, true});
            }
        }
    }
    ll ans = min(dist[n - 1][0], dist[n - 1][1]);
    output(ans);
}
