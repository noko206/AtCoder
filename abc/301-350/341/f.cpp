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
    vector<int> _u(m), _v(m), w(n);
    vector<ll> a(n);
    REP(i, m) cin >> _u[i] >> _v[i], --_u[i], --_v[i];
    REP(i, n) cin >> w[i];
    REP(i, n) cin >> a[i];
    vector<vector<int>> to(n);
    REP(i, m) {
        if (w[_u[i]] > w[_v[i]]) {
            to[_u[i]].push_back(_v[i]);
        }
        if (w[_v[i]] > w[_u[i]]) {
            to[_v[i]].push_back(_u[i]);
        }
    }
    vector<int> dp(n, -1);
    auto dfs = [&](auto &dfs, int v) -> int {
        if (dp[v] != -1) return dp[v];
        if (to[v].size() == 0) return dp[v] = 1;
        ll sum = 0;
        vector<int> weight;
        vector<int> value;
        int maxV = 0;
        for (int u : to[v]) {
            weight.push_back(w[u]);
            int _value = dfs(dfs, u);
            value.push_back(_value);
            maxV += _value;
        }
        vector _dp(to[v].size() + 1, vector<int>(maxV + 1, INF32));
        _dp[0][0] = 0;
        REP(i, to[v].size()) {
            REP(j, maxV + 1) {
                chmin(_dp[i + 1][j], _dp[i][j]);
                if (j - value[i] >= 0) {
                    chmin(_dp[i + 1][j], _dp[i][j - value[i]] + weight[i]);
                }
            }
        }
        int ans = 1;
        REP(i, maxV + 1) {
            if (_dp[to[v].size()][i] < w[v]) {
                chmax(ans, i + 1);
            }
        }
        return dp[v] = ans;
    };
    REP(v, n) dfs(dfs, v);
    ll ans = 0;
    REP(i, n) { ans += (ll)dp[i] * a[i]; }
    output(ans);
}
