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
    vector a(3, vector<ll>(3));
    REP(i, 3) REP(j, 3) cin >> a[i][j];
    vector<ll> dp(pow(3, 9));  // 高橋君の相対的な得点
    vector<ll> seen(pow(3, 9), false);
    vector color(3, vector<int>(3, 0));  // 1:red, 2:blue
    auto dfs = [&](auto &dfs, int cnt = 0) -> ll {
        // dp計算済み
        int pos = 0;
        REP(i, 3) {
            REP(j, 3) {
                pos *= 3;
                pos += color[i][j];
            }
        }
        if (seen[pos]) {
            return dp[pos];
        }
        seen[pos] = true;
        // 3つ連続による終了
        bool win_takahashi = false;
        bool win_aoki = false;
        REP(i, 3) {
            bool takahashi = true;
            bool aoki = true;
            REP(j, 3) {
                if (color[i][j] != 1) takahashi = false;
                if (color[i][j] != 2) aoki = false;
            }
            if (takahashi) win_takahashi = true;
            if (aoki) win_aoki = true;
        }
        REP(j, 3) {
            bool takahashi = true;
            bool aoki = true;
            REP(i, 3) {
                if (color[i][j] != 1) takahashi = false;
                if (color[i][j] != 2) aoki = false;
            }
            if (takahashi) win_takahashi = true;
            if (aoki) win_aoki = true;
        }
        {
            bool takahashi = true;
            bool aoki = true;
            REP(i, 3) {
                if (color[i][i] != 1) takahashi = false;
                if (color[i][i] != 2) aoki = false;
            }
            if (takahashi) win_takahashi = true;
            if (aoki) win_aoki = true;
        }
        {
            bool takahashi = true;
            bool aoki = true;
            REP(i, 3) {
                if (color[2 - i][i] != 1) takahashi = false;
                if (color[2 - i][i] != 2) aoki = false;
            }
            if (takahashi) win_takahashi = true;
            if (aoki) win_aoki = true;
        }
        if (win_takahashi) {
            return dp[pos] = INF64;
        }
        if (win_aoki) {
            return dp[pos] = -INF64;
        }
        // 9つ塗られて終了
        if (cnt == 9) {
            // 高橋君-青木君を求める
            ll sum = 0;
            REP(i, 3) {
                REP(j, 3) {
                    if (color[i][j] == 1) {
                        sum += a[i][j];
                    } else {
                        sum -= a[i][j];
                    }
                }
            }
            return dp[pos] = sum;
        }
        if (cnt % 2 == 0) {
            // 高橋君
            ll mx = -INF64;
            REP(i, 3) {
                REP(j, 3) {
                    if (color[i][j] == 0) {
                        color[i][j] = 1;
                        chmax(mx, dfs(dfs, cnt + 1));
                        color[i][j] = 0;
                    }
                }
            }
            return dp[pos] = mx;
        } else {
            // 青木君
            ll mn = INF64;
            REP(i, 3) {
                REP(j, 3) {
                    if (color[i][j] == 0) {
                        color[i][j] = 2;
                        chmin(mn, dfs(dfs, cnt + 1));
                        color[i][j] = 0;
                    }
                }
            }
            return dp[pos] = mn;
        }
    };
    output(dfs(dfs) > 0LL ? "Takahashi" : "Aoki");
}
