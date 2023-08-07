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
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    REP(i, n) {
        cout << '?';
        REP(j, k) { cout << ' ' << ((i + j) % n) + 1; }
        cout << endl;
        cin >> res[i];
    }
    vector<int> ans(n, -1);
    // とりあえず0にしておく
    ans[0] = 0;
    int j = 0;
    while (ans[(j + k) % 2] == -1) {
        int p = abs(res[j] - res[(j + 1) % n]) % 2;
        if (p == 0) {
            ans[j + k] = ans[j];
        } else {
            ans[j + k] = (ans[j] + 1) % 2;
        }
        j += k;
    }
    // 整合性チェック
    int p = 0;
    REP(i, k) { p += ans[i]; }
    p %= 2;
    bool is_ok = true;
    REP(i, n) {
        if (p != res[i]) {
            is_ok = false;
        }
        p -= ans[i];
        p += ans[(i + k) % n];
        p = (p + 2) % 2;
    }
    if (!is_ok) {
        REP(i, n) { ans[i] = ans[i] ? 0 : 1; }
    }
    // 出力
    cout << '!';
    REP(i, n) { cout << ' ' << ans[i]; }
    cout << endl;
}
