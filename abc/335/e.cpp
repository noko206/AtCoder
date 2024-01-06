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
    vector<int> a(n);
    REP(i, n) cin >> a[i], --a[i];
    vector<vector<int>> to(n);
    vector<vector<int>> a_list(200000);
    dsu uf(n);
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
        a_list[a[u]].push_back(u);
        a_list[a[v]].push_back(v);
        if (a[u] == a[v] && !uf.same(u, v)) {
            uf.merge(u, v);
        }
    }
    vector<int> dp(n, -INF32);
    int zr = uf.leader(0);
    dp[zr] = 1;
    REP(i, 200000) {
        for (int v : a_list[i]) {
            // u->v
            int vr = uf.leader(v);
            for (int u : to[v]) {
                int ur = uf.leader(u);
                if (a[u] < a[v]) {
                    chmax(dp[vr], dp[ur] + 1);
                }
            }
        }
    }
    int nr = uf.leader(n - 1);
    output(dp[nr] < 0 ? 0 : dp[nr]);
}
