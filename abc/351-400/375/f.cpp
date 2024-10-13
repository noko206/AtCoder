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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m), b(m), c(m);
    REP(i, m) cin >> a[i] >> b[i] >> c[i], --a[i], --b[i];
    vector<vector<int>> query(q);
    set<int> st;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;
            query[i].push_back(t);
            query[i].push_back(x);
            st.insert(x);
        } else {
            int x, y;
            cin >> x >> y;
            --x, --y;
            query[i].push_back(t);
            query[i].push_back(x);
            query[i].push_back(y);
        }
    }
    vector dp(n, vector<ll>(n, INF64));
    REP(i, m) {
        if (st.find(i) != st.end()) continue;
        dp[a[i]][b[i]] = c[i];
        dp[b[i]][a[i]] = c[i];
    }
    REP(i, n) dp[i][i] = 0;
    REP(k, n) {
        REP(i, n) {
            REP(j, n) { chmin(dp[i][j], dp[i][k] + dp[k][j]); }
        }
    }
    vector<ll> ans;
    reverse(ALL(query));
    REP(k, q) {
        if (query[k][0] == 1) {
            int idx = query[k][1];
            chmin(dp[a[idx]][b[idx]], (ll)c[idx]);
            chmin(dp[b[idx]][a[idx]], (ll)c[idx]);
            REP(i, n) {
                REP(j, n) {
                    chmin(dp[i][j],
                          dp[i][a[idx]] + dp[a[idx]][b[idx]] + dp[b[idx]][j]);
                    chmin(dp[i][j],
                          dp[i][b[idx]] + dp[b[idx]][a[idx]] + dp[a[idx]][j]);
                }
            }
        } else {
            int x = query[k][1], y = query[k][2];
            ans.push_back(dp[x][y] == INF64 ? -1 : dp[x][y]);
        }
    }
    reverse(ALL(ans));
    REP(i, ans.size()) output(ans[i]);
}
