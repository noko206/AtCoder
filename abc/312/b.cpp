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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    REP(i, n - 8) {
        REP(j, m - 8) {
            bool is_ok = true;
            // 条件2
            REP(y, 3) {
                REP(x, 3) {
                    int ny = y + i;
                    int nx = x + j;
                    if (s[ny][nx] == '.') is_ok = false;
                }
            }
            REP(y, 3) {
                REP(x, 3) {
                    int ny = y + 6 + i;
                    int nx = x + 6 + j;
                    if (s[ny][nx] == '.') is_ok = false;
                }
            }
            // 条件3
            REP(y, 4) {
                int ny = y + i;
                int nx = 3 + j;
                if (s[ny][nx] == '#') is_ok = false;
            }
            REP(x, 4) {
                int ny = 3 + i;
                int nx = x + j;
                if (s[ny][nx] == '#') is_ok = false;
            }
            REP(y, 4) {
                int ny = y + 5 + i;
                int nx = 5 + j;
                if (s[ny][nx] == '#') is_ok = false;
            }
            REP(x, 4) {
                int ny = 5 + i;
                int nx = x + 5 + j;
                if (s[ny][nx] == '#') is_ok = false;
            }
            if (is_ok) {
                output(i + 1, j + 1);
            }
        }
    }
}
