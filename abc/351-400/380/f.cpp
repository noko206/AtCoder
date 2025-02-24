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
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n + m + l);
    string s = "";
    REP(i, n) cin >> a[i], s += "a";
    REP(i, m) cin >> a[i + n], s += "b";
    REP(i, l) cin >> a[i + n + m], s += "c";
    map<pair<string, bool>, bool> dp;
    auto dfs = [&](auto &dfs, string s, bool is_takahashi = true) -> bool {
        if (dp.find({s, is_takahashi}) != dp.end())
            return dp[{s, is_takahashi}];
        REP(i, s.length()) {
            REP(j, s.length()) {
                if (i == j) continue;
                if (is_takahashi) {
                    // 高橋君
                    if (s[i] != 'a' || s[j] != 'c') continue;
                    if (a[i] > a[j]) {
                        // 交換する
                        string t = s;
                        swap(t[i], t[j]);
                        if (dfs(dfs, t, !is_takahashi)) {
                            return dp[{s, is_takahashi}] = true;
                        }
                    } else {
                        // 交換しない
                        string t = s;
                        t[i] = 'c';
                        if (dfs(dfs, t, !is_takahashi)) {
                            return dp[{s, is_takahashi}] = true;
                        }
                    }
                } else {
                    // 青木君
                    if (s[i] != 'b' || s[j] != 'c') continue;
                    if (a[i] > a[j]) {
                        // 交換する
                        string t = s;
                        swap(t[i], t[j]);
                        if (!dfs(dfs, t, !is_takahashi)) {
                            return dp[{s, is_takahashi}] = false;
                        }
                    } else {
                        // 交換しない
                        string t = s;
                        t[i] = 'c';
                        if (!dfs(dfs, t, !is_takahashi)) {
                            return dp[{s, is_takahashi}] = false;
                        }
                    }
                }
            }
        }
        // 操作が行えなかったとき
        if (is_takahashi) {
            return dp[{s, is_takahashi}] = false;
        } else {
            return dp[{s, is_takahashi}] = true;
        }
    };
    output(dfs(dfs, s) ? "Takahashi" : "Aoki");
}
