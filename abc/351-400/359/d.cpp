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

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<unordered_map<string, mint>> dp(n);
    // 初期化
    REP(bit, 1 << k) {
        string t = "";
        bool is_ok = true;
        REP(i, k) {
            if (bit & (1 << i)) {
                if (s[i] == 'B') {
                    is_ok = false;
                }
                t += "A";
            } else {
                if (s[i] == 'A') {
                    is_ok = false;
                }
                t += "B";
            }
        }
        if (!is_ok) continue;
        bool is_kaibun = true;
        REP(i, k) {
            if (t[i] != t[k - i - 1]) {
                is_kaibun = false;
            }
        }
        if (is_kaibun) continue;
        dp[0][t] = 1;
    }
    // DP
    REP(i, n) {
        if (i + k >= n) break;
        for (auto [t, v] : dp[i]) {
            // Aの場合
            if (s[i + k] == 'A' || s[i + k] == '?') {
                string u = t.substr(1) + "A";
                bool is_kaibun = true;
                REP(j, k) {
                    if (u[j] != u[k - j - 1]) {
                        is_kaibun = false;
                    }
                }
                if (!is_kaibun) {
                    dp[i + 1][u] += v;
                }
            }
            // Bの場合
            if (s[i + k] == 'B' || s[i + k] == '?') {
                string u = t.substr(1) + "B";
                bool is_kaibun = true;
                REP(j, k) {
                    if (u[j] != u[k - j - 1]) {
                        is_kaibun = false;
                    }
                }
                if (!is_kaibun) {
                    dp[i + 1][u] += v;
                }
            }
        }
    }
    mint ans = 0;
    for (auto [_, v] : dp[n - k]) {
        ans += v;
    }
    output(ans.val());
}
