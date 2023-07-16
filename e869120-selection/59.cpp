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
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n), r(n);
    REP(i, n) cin >> c[i] >> r[i];
    vector<vector<int>> to(n);
    REP(i, k) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<vector<int>> add_edges(n);
    REP(i, n) {
        queue<int> q;
        q.push(i);
        vector<int> dist(n, INF32);
        dist[i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : to[v]) {
                if (chmin(dist[u], dist[v] + 1)) {
                    q.push(u);
                }
            }
        }
        REP(j, n) {
            if (0 < dist[j] && dist[j] <= r[i]) {
                add_edges[i].push_back(j);
            }
        }
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    vector<int> dist(n, INF32);
    dist[0] = 0;
    while (!pq.empty()) {
        auto [dv, v] = pq.top();
        pq.pop();
        if (dv > dist[v]) continue;
        for (int u : to[v]) {
            if (chmin(dist[u], dist[v] + c[v])) {
                pq.push({dist[u], u});
            }
        }
        for (int u : add_edges[v]) {
            if (chmin(dist[u], dist[v] + c[v])) {
                pq.push({dist[u], u});
            }
        }
    }
    output(dist[n - 1]);
}
