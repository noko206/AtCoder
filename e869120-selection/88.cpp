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
    vector<pair<int, int>> p;
    REP(i, n) {
        int c;
        cin >> c;
        int m = (int)p.size();
        if (i % 2 == 0) {
            if (m == 0) {
                p.push_back({c, 1});
            } else {
                auto [c1, cnt1] = p[m - 1];
                if (c == c1) {
                    ++p[m - 1].second;
                } else {
                    p.push_back({c, 1});
                }
            }
        } else {
            if (m == 0) {
                p.push_back({c, 1});
            } else if (m == 1) {
                auto [c1, cnt1] = p[0];
                p[0].first = c;
                ++p[0].second;
            } else {
                auto [c1, cnt1] = p[m - 1];
                auto [c2, cnt2] = p[m - 2];
                if (c == c1) {
                    ++p[m - 1].second;
                } else {
                    p.pop_back();
                    p[m - 2].second += cnt1 + 1;
                }
            }
        }
    }
    int ans = 0;
    for (auto [c, cnt] : p) {
        if (c == 0) ans += cnt;
        // REP(i, cnt) cout << c << ' ';
    }
    // cout << endl;
    output(ans);
}
