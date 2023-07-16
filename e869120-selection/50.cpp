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
    int n, m;
    cin >> n >> m;
    vector edge_id(n, vector<int>(n, -1));
    vector edge_dist(n, vector<ll>(n, -1));
    vector<ll> time(m);
    REP(i, m) {
        int s, t;
        ll d;
        cin >> s >> t >> d >> time[i];
        --s, --t;
        edge_id[s][t] = i;
        edge_id[t][s] = i;
        edge_dist[s][t] = d;
        edge_dist[t][s] = d;
    }
    vector dp(1 << n, vector<ll>(n, 0));
    dp[0][0] = 1;
    vector dist(1 << n, vector<ll>(n, INF64));
    dist[0][0] = 0;
    REP(bit, 1 << n) {
        REP(i, n) {
            if (bit != 0 && !(bit & (1 << i))) continue;
            REP(j, n) {
                int e_id = edge_id[i][j];
                ll e_dist = edge_dist[i][j];
                if (bit & (1 << j)) continue;
                if (e_dist == -1) continue;
                if (e_id == -1) continue;
                if (dist[bit][i] + e_dist > time[e_id]) continue;
                if (dist[bit | (1 << j)][j] < dist[bit][i] + e_dist) continue;

                if (dist[bit | (1 << j)][j] == dist[bit][i] + e_dist) {
                    dp[bit | (1 << j)][j] += dp[bit][i];
                } else {
                    dp[bit | (1 << j)][j] = dp[bit][i];
                }
                dist[bit | (1 << j)][j] = dist[bit][i] + e_dist;
            }
        }
    }
    if (dp[(1 << n) - 1][0] == 0)
        output("IMPOSSIBLE");
    else
        output(dist[(1 << n) - 1][0], dp[(1 << n) - 1][0]);
}
