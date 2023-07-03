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
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    map<pair<int, int>, bool> mp;
    REP(i, n) { mp[{x[i], y[i]}] = true; }
    int ans = 0;
    REP(i, n) {
        mp[{x[i], y[i]}] = false;
        REP(j, i) {
            mp[{x[j], y[j]}] = false;
            int xo = x[i] + x[j];
            int yo = y[i] + y[j];
            int x1 = 2 * x[i] - xo;
            int y1 = 2 * y[i] - yo;
            int x2 = -y1 + xo;
            int y2 = x1 + yo;
            int x3 = y1 + xo;
            int y3 = -x1 + yo;
            if (x2 % 2 != 0 || y2 % 2 != 0 || x3 % 2 != 0 || y3 % 2 != 0) {
                mp[{x[j], y[j]}] = true;
                continue;
            }
            x2 /= 2;
            y2 /= 2;
            x3 /= 2;
            y3 /= 2;
            if (mp.find({x2, y2}) == mp.end() || !mp[{x2, y2}]) {
                mp[{x[j], y[j]}] = true;
                continue;
            }
            if (mp.find({x3, y3}) == mp.end() || !mp[{x3, y3}]) {
                mp[{x[j], y[j]}] = true;
                continue;
            }
            chmax(ans, ((x[i] - x[j]) * (x[i] - x[j]) +
                        (y[i] - y[j]) * (y[i] - y[j])) /
                           2);
            mp[{x[j], y[j]}] = true;
        }
        mp[{x[i], y[i]}] = true;
    }
    output(ans);
}
