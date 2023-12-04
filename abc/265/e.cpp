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
using mint = modint998244353;

mint dp[305][305][305];

int main() {
    int n, m;
    cin >> n >> m;
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    map<pair<ll, ll>, bool> mp;
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = true;
    }
    dp[0][0][0] = 1;
    REP(i, n) REP(j, i + 1) REP(k, i + 1 - j) {
        {
            ll x = j * a + k * c + (i + 1 - j - k) * e;
            ll y = j * b + k * d + (i + 1 - j - k) * f;
            if (mp.find({x, y}) == mp.end()) {
                dp[i + 1][j][k] += dp[i][j][k];
            }
        }
        {
            ll x = (j + 1) * a + k * c + (i - j - k) * e;
            ll y = (j + 1) * b + k * d + (i - j - k) * f;
            if (j + 1 <= n && mp.find({x, y}) == mp.end()) {
                dp[i + 1][j + 1][k] += dp[i][j][k];
            }
        }
        {
            ll x = j * a + (k + 1) * c + (i - j - k) * e;
            ll y = j * b + (k + 1) * d + (i - j - k) * f;
            if (k + 1 <= n && mp.find({x, y}) == mp.end()) {
                dp[i + 1][j][k + 1] += dp[i][j][k];
            }
        }
    }
    mint ans = 0;
    REP(i, n + 1) {
        REP(j, n + 1) { ans += dp[n][i][j]; }
    }
    output(ans.val());
}
