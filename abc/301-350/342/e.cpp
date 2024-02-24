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
    int n, m;
    cin >> n >> m;
    vector<ll> l(m), d(m), k(m), c(m);
    vector<vector<P>> to(n);
    REP(i, m) {
        int a, b;
        cin >> l[i] >> d[i] >> k[i] >> c[i] >> a >> b;
        --a, --b;
        to[b].emplace_back(a, i);
    }
    vector<ll> dp(n, -1);  // tを最大化したい
    dp[n - 1] = INF64;
    priority_queue<pair<ll, int>> pq;
    pq.push({INF64, n - 1});
    while (!pq.empty()) {
        auto [vt, v] = pq.top();
        pq.pop();
        // 枝刈り
        if (vt < dp[v]) continue;
        for (auto [u, i] : to[v]) {
            // 二分探索
            ll ok = -1;
            ll ng = k[i];
            while (ng - ok != 1) {
                ll mid = (ok + ng) / 2;
                if (l[i] + mid * d[i] + c[i] <= vt) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            // 到達できない場合
            if (ok == -1) continue;
            // 最大値に更新できれば、さらに探索
            if (chmax(dp[u], l[i] + ok * d[i])) {
                pq.push({dp[u], u});
            }
        }
    }
    REP(i, n - 1) {
        if (dp[i] == -1) {
            output("Unreachable");
        } else {
            output(dp[i]);
        }
    }
}
