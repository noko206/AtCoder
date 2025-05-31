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
    vector<vector<P>> to(n);
    REP(i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        to[u].emplace_back(w, v);
        to[v].emplace_back(w, u);
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    vector dist(n, vector<ll>(35, INF64));
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto [wv, v] = pq.top();
        pq.pop();
        int bitv = __builtin_popcountll(wv);
        if (wv > dist[v][bitv]) continue;
        for (auto [wu, u] : to[v]) {
            int bitsum = __builtin_popcountll(bitv | wu);
            if (chmin(dist[u][bitsum], dist[v][bitv] | wu)) {
                pq.push({dist[u][bitsum], u});
            }
        }
    }
    ll ans = INF64;
    REP(i, 35) chmin(ans, dist[n - 1][i]);
    output(ans);
}
