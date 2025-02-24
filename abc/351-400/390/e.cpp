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
vector<vector<ll>> f(const vector<ll> &a, const vector<ll> &c, int x) {
    vector dp(a.size() + 1, vector<ll>(x + 1, 0));
    REP(i, a.size()) {
        REP(j, x + 1) {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j - c[i] >= 0) {
                chmax(dp[i + 1][j], dp[i][j - c[i]] + a[i]);
            }
        }
    }
    return dp;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<ll>> a(3), c(3);
    REP(i, n) {
        int v, _a, _c;
        cin >> v >> _a >> _c;
        --v;
        a[v].push_back(_a);
        c[v].push_back(_c);
    }
    vector<vector<vector<ll>>> dp(3);
    REP(i, 3) { dp[i] = f(a[i], c[i], x); }
    ll ok = 0;
    ll ng = INF32;
    while (ng - ok != 1) {
        ll mid = (ok + ng) / 2;
        int needX = 0;
        REP(i, 3) {
            needX += lower_bound(ALL(dp[i][a[i].size()]), mid) -
                     dp[i][a[i].size()].begin();
        }
        if (needX <= x) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    output(ok);
}
