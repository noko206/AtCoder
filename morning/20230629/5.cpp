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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h) cin >> a[i];
    vector memo(h, vector<int>(w));
    vector visited(h, vector<bool>(w, false));
    auto dfs = [&](auto &dfs, int y, int x) -> int {
        if (visited[y][x]) return memo[y][x];
        visited[y][x] = true;
        if (y == h - 1 && x == w - 1) return memo[y][x] = 0;
        if ((x + y) % 2 == 0) {
            // Takahashi
            memo[y][x] = -INF32;
            if (y + 1 < h)
                chmax(memo[y][x],
                      dfs(dfs, y + 1, x) + (a[y + 1][x] == '+' ? 1 : -1));
            if (x + 1 < w)
                chmax(memo[y][x],
                      dfs(dfs, y, x + 1) + (a[y][x + 1] == '+' ? 1 : -1));
        } else {
            // Aoki
            memo[y][x] = INF32;
            if (y + 1 < h)
                chmin(memo[y][x],
                      dfs(dfs, y + 1, x) - (a[y + 1][x] == '+' ? 1 : -1));
            if (x + 1 < w)
                chmin(memo[y][x],
                      dfs(dfs, y, x + 1) - (a[y][x + 1] == '+' ? 1 : -1));
        }
        return memo[y][x];
    };
    dfs(dfs, 0, 0);
    if (memo[0][0] > 0) {
        output("Takahashi");
    } else if (memo[0][0] < 0) {
        output("Aoki");
    } else {
        output("Draw");
    }
}
