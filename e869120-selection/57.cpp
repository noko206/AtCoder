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
    int n, k;
    cin >> n >> k;
    vector<vector<P>> to(n);
    vector<ll> ans;
    REP(i, k) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            vector<ll> dist(n, INF64);
            dist[a] = 0;
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0, a});
            while (!pq.empty()) {
                auto [dv, v] = pq.top();
                pq.pop();
                if (dv > dist[v]) continue;
                for (auto [du, u] : to[v]) {
                    if (chmin(dist[u], dist[v] + du)) {
                        pq.push({dist[u], u});
                    }
                }
            }
            ans.push_back(dist[b] == INF64 ? -1 : dist[b]);
        } else {
            int c, d, e;
            cin >> c >> d >> e;
            --c, --d;
            to[c].emplace_back(e, d);
            to[d].emplace_back(e, c);
        }
    }
    for (ll v : ans) {
        output(v);
    }
}
