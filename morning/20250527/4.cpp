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
    int x, y;
    string w;
    cin >> x >> y >> w;
    --x, --y;
    vector<string> c(9);
    REP(i, 9) cin >> c[i];
    string ans = "";
    REP(i, 4) {
        int ny = y, nx = x;
        if (w == "R" || w == "RU" || w == "RD") {
            if (x + i < 9) {
                nx = x + i;
            } else {
                nx = 8 - (x + i - 8);
            }
        }
        if (w == "L" || w == "LU" || w == "LD") {
            if (x - i >= 0) {
                nx = x - i;
            } else {
                nx = -(x - i);
            }
        }
        if (w == "U" || w == "RU" || w == "LU") {
            if (y - i >= 0) {
                ny = y - i;
            } else {
                ny = -(y - i);
            }
        }
        if (w == "D" || w == "RD" || w == "LD") {
            if (y + i < 9) {
                ny = y + i;
            } else {
                ny = 8 - (y + i - 8);
            }
        }
        ans += c[ny][nx];
    }
    output(ans);
}
