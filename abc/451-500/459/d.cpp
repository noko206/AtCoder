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
pair<bool, string> solve(string s) {
    vector<int> cnt(26, 0);
    int n = s.length();
    REP(i, n) { ++cnt[s[i] - 'a']; }
    vector<pair<int, char>> p(26);
    REP(i, 26) { p[i] = {cnt[i], 'a' + i}; }
    sort(ALLR(p));
    string ans = "";
    REP(i, n) ans += "?";
    int pos = 0;
    for (auto [num, c] : p) {
        REP(i, num) {
            ans[pos] = c;
            pos += 2;
            if (pos >= n) {
                pos = 1;
            }
        }
    }
    bool is_ok = true;
    REP(i, n - 1) {
        if (ans[i] == ans[i + 1]) {
            is_ok = false;
        }
    }
    return {is_ok, ans};
}

int main() {
    int t;
    cin >> t;
    vector<pair<bool, string>> ans(t);
    REP(i, t) {
        string s;
        cin >> s;
        ans[i] = solve(s);
    }
    for (auto [is_ok, s] : ans) {
        if (is_ok) {
            output("Yes");
            output(s);
        } else {
            output("No");
        }
    }
}
