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
    int n;
    cin >> n;
    vector<string> c(n);
    REP(i, n) cin >> c[i];
    vector<vector<int>> memo(n, vector<int>(n, INF32));
    vector from(26, vector<vector<int>>(n));
    vector to(26, vector<vector<int>>(n));
    REP(i, n) {
        REP(j, n) {
            if (c[i][j] != '-') {
                from[c[i][j] - 'a'][i].push_back(j);
                to[c[i][j] - 'a'][j].push_back(i);
            }
        }
    }
    auto dfs = [&](auto &dfs, int s, int e, int cnt = 0) -> int {
        if (cnt >= n * n * 2) {
            return INF32;
        }
        if (memo[s][e] != INF32) {
            return memo[s][e];
        }
        if (s == e) {
            return memo[s][e] = 0;
        }
        if (c[s][e] != '-') {
            return memo[s][e] = 1;
        }
        int ans = INF32;
        REP(k, 26) {
            for (int i : from[k][s]) {
                for (int j : to[k][e]) {
                    if (i == s && j == e) continue;
                    chmin(ans, dfs(dfs, i, j, cnt + 1) + 2);
                }
            }
        }
        return memo[s][e] = ans;
    };
    vector<vector<int>> ans(n, vector<int>(n));
    REP(i, n) {
        REP(j, n) {
            int tmp = dfs(dfs, i, j);
            ans[i][j] = tmp == INF32 ? -1 : tmp;
        }
    }
    REP(i, n) output(ans[i]);
}
