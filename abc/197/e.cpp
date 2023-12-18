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
    vector<vector<int>> cnt(n + 1);
    REP(i, n) {
        int x, c;
        cin >> x >> c;
        --c;
        cnt[c].push_back(x);
    }
    cnt[n].push_back(0);
    ++n;
    REP(i, n) sort(ALL(cnt[i]));
    vector dp(n + 1, vector<ll>(2, INF64));
    dp[0][0] = 0;
    vector<int> pre = {0, 0};
    REP(i, n) {
        if (cnt[i].size() == 0) {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];
            continue;
        }
        vector<int> now = {cnt[i][0], cnt[i][cnt[i].size() - 1]};
        REP(j, 2) {
            REP(k, 2) {
                // k->j
                ll d = abs(pre[k] - now[(j + 1) % 2]);
                d += abs(now[(j + 1) % 2] - now[j]);
                chmin(dp[i + 1][j], dp[i][k] + d);
            }
        }
        pre = now;
    }
    ll ans = min(dp[n][0], dp[n][1]);
    output(ans);
}
