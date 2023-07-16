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
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int p, q;
    cin >> p >> q;
    vector<int> c(k);
    REP(i, k) {
        cin >> c[i];
        --c[i];
    }
    vector<vector<int>> to(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<bool> is_zonbie(n, false);
    vector<bool> is_danger(n, false);
    auto bfs = [&]() -> void {
        priority_queue<P> pq;
        vector<ll> dist(n, -1);
        REP(i, k) {
            pq.push({s, c[i]});
            dist[c[i]] = s;
        }
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (d < dist[v]) continue;
            for (int u : to[v]) {
                if (chmax(dist[u], dist[v] - 1)) {
                    pq.push({dist[u], u});
                }
            }
        }
        REP(i, n) {
            if (dist[i] == s) {
                is_zonbie[i] = true;
            } else if (dist[i] >= 0) {
                is_danger[i] = true;
            }
        }
    };
    bfs();
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    vector<ll> dist(n, INF64);
    dist[0] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        for (int u : to[v]) {
            if (is_zonbie[u]) continue;
            int cost = is_danger[u] ? q : p;
            if (u == n - 1) cost = 0;
            if (chmin(dist[u], dist[v] + cost)) {
                pq.push({dist[u], u});
            }
        }
    }
    output(dist[n - 1]);
}
