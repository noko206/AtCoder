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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    int ok = h * w + 1;
    int ng = -1;
    while (ok - ng != 1) {
        int mid = (ok + ng) / 2;
        bool is_ok = false;
        REP(row, h) {
            int j = 0;
            int cnt = 0;
            REP(i, w) {
                while (j < w && cnt <= mid) {
                    if (s[row][j] == 'x') break;
                    if (cnt == mid && s[row][j] == '.') break;
                    if (s[row][j] == '.') ++cnt;
                    ++j;
                }
                if (j - i >= k) {
                    is_ok = true;
                }
                if (s[row][i] == '.') cnt = max(cnt - 1, 0);
                if (j == i) j = i + 1;
            }
        }
        REP(col, w) {
            int j = 0;
            int cnt = 0;
            REP(i, h) {
                while (j < h && cnt <= mid) {
                    if (s[j][col] == 'x') break;
                    if (cnt == mid && s[j][col] == '.') break;
                    if (s[j][col] == '.') ++cnt;
                    ++j;
                }
                if (j - i >= k) {
                    is_ok = true;
                }
                if (s[i][col] == '.') cnt = max(cnt - 1, 0);
                if (j == i) j = i + 1;
            }
        }
        if (is_ok) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    if (ok == h * w + 1) {
        output(-1);
    } else {
        output(ok);
    }
}
