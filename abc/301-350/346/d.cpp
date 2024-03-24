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
    string s;
    cin >> s;
    vector<int> c(n);
    REP(i, n) cin >> c[i];
    vector left(2, vector<ll>(n + 1, 0));
    vector right(2, vector<ll>(n + 1, 0));
    REP(i, n) {
        if (i % 2 == 0) {
            if (s[i] == '1') {
                left[0][i + 1] += c[i];
            }
            left[0][i + 1] += left[0][i];
            if (s[n - i - 1] == '1') {
                right[0][i + 1] += c[n - i - 1];
            }
            right[0][i + 1] += right[0][i];
        } else {
            if (s[i] == '0') {
                left[0][i + 1] += c[i];
            }
            left[0][i + 1] += left[0][i];
            if (s[n - i - 1] == '0') {
                right[0][i + 1] += c[n - i - 1];
            }
            right[0][i + 1] += right[0][i];
        }
    }
    REP(i, n) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                left[1][i + 1] += c[i];
            }
            left[1][i + 1] += left[1][i];
            if (s[n - i - 1] == '0') {
                right[1][i + 1] += c[n - i - 1];
            }
            right[1][i + 1] += right[1][i];
        } else {
            if (s[i] == '1') {
                left[1][i + 1] += c[i];
            }
            left[1][i + 1] += left[1][i];
            if (s[n - i - 1] == '1') {
                right[1][i + 1] += c[n - i - 1];
            }
            right[1][i + 1] += right[1][i];
        }
    }
    ll ans = INF64;
    if (n % 2 == 0) {
        REP(i, 1, n) {
            chmin(ans, left[0][i] + right[0][n - i]);
            chmin(ans, left[1][i] + right[1][n - i]);
        }
    } else {
        REP(i, 1, n) {
            chmin(ans, left[0][i] + right[1][n - i]);
            chmin(ans, left[1][i] + right[0][n - i]);
        }
    }
    output(ans);
}
