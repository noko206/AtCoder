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
    string r, c;
    cin >> r >> c;
    vector used(n, vector<bool>(n, false));  // A,B,C,none,none
    bool is_ok = false;
    string s = "ABC..";
    vector<string> ans;
    auto dfs = [&](auto &dfs) -> void {
        if (ans.size() == n) {
            // r,cの条件を満たすか判定
            bool ok = true;
            REP(i, n) {
                REP(j, n) {
                    if (ans[i][j] == '.') continue;
                    if (ans[i][j] != r[i]) ok = false;
                    break;
                }
            }
            REP(j, n) {
                REP(i, n) {
                    if (ans[i][j] == '.') continue;
                    if (ans[i][j] != c[j]) ok = false;
                    break;
                }
            }
            if (!ok) return;
            is_ok = true;
            return;
        }
        vector<int> p(n);
        REP(i, n) p[i] = i;
        do {
            bool ok = true;
            REP(i, n) {
                if (used[i][p[i]]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            REP(i, n) { used[i][p[i]] = true; }
            string t = "";
            REP(i, n) { t += s[p[i]]; }
            ans.push_back(t);
            dfs(dfs);
            if (is_ok) return;
            REP(i, n) { used[i][p[i]] = false; }
            ans.pop_back();
        } while (next_permutation(ALL(p)));
    };
    dfs(dfs);
    if (is_ok) {
        output("Yes");
        REP(i, n) { output(ans[i]); }
    } else {
        output("No");
    }
}
