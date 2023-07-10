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
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
const int dy_even[] = {-1, 0, 1, 1, 0, -1};
const int dx_even[] = {1, 1, 1, 0, -1, 0};

const int dy_odd[] = {-1, 0, 1, 1, 0, -1};
const int dx_odd[] = {0, 1, 0, -1, -1, -1};

int main() {
    int w, h;
    cin >> w >> h;
    vector a(h, vector<int>(w));
    REP(i, h) REP(j, w) cin >> a[i][j];
    vector visited(h, vector<bool>(w, false));
    ll ans = 0;
    auto dfs1 = [&](auto &dfs1, int y, int x) -> void {
        visited[y][x] = true;
        int cnt = 6;
        REP(i, 6) {
            int ny = y + (y % 2 == 0 ? dy_even[i] : dy_odd[i]);
            int nx = x + (y % 2 == 0 ? dx_even[i] : dx_odd[i]);
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (a[ny][nx] == 0) continue;
            --cnt;
            if (visited[ny][nx]) continue;
            dfs1(dfs1, ny, nx);
        }
        ans += cnt;
    };
    auto dfs2 = [&](auto &dfs2, int y, int x) -> void {
        visited[y][x] = true;
        int cnt = 6;
        REP(i, 6) {
            int ny = y + (y % 2 == 0 ? dy_even[i] : dy_odd[i]);
            int nx = x + (y % 2 == 0 ? dx_even[i] : dx_odd[i]);
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (a[ny][nx] == 1) continue;
            --cnt;
            if (visited[ny][nx]) continue;
            dfs2(dfs2, ny, nx);
        }
        ans -= cnt;
    };
    vector pre_visited(h, vector<bool>(w, false));
    auto dfs3 = [&](auto &dfs3, int y, int x) -> bool {
        pre_visited[y][x] = true;
        bool is_ok = true;
        REP(i, 6) {
            int ny = y + (y % 2 == 0 ? dy_even[i] : dy_odd[i]);
            int nx = x + (y % 2 == 0 ? dx_even[i] : dx_odd[i]);
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
                is_ok = false;
                continue;
            }
            if (a[ny][nx] == 1) continue;
            if (pre_visited[ny][nx]) continue;
            if (!dfs3(dfs3, ny, nx)) {
                is_ok = false;
            }
        }
        return is_ok;
    };
    REP(i, h) {
        REP(j, w) {
            if (visited[i][j] || pre_visited[i][j]) continue;
            if (a[i][j] == 1) {
                dfs1(dfs1, i, j);
            } else if (dfs3(dfs3, i, j)) {
                dfs2(dfs2, i, j);
            }
        }
    }
    output(ans);
}
