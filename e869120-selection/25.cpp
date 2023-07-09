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
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    vector<int> ans;
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector c(h, vector<int>(w));
        REP(i, h) REP(j, w) cin >> c[i][j];
        vector visited(h, vector<bool>(w, false));
        auto dfs = [&](auto &dfs, int x, int y) -> void {
            visited[y][x] = true;
            REP(i, 8) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                if (visited[ny][nx]) continue;
                if (c[ny][nx] == 0) continue;
                dfs(dfs, nx, ny);
            }
        };
        int cnt = 0;
        REP(i, h) {
            REP(j, w) {
                if (visited[i][j]) continue;
                if (c[i][j] == 0) continue;
                dfs(dfs, j, i);
                ++cnt;
            }
        }
        ans.push_back(cnt);
    }
    for (int v : ans) {
        output(v);
    }
}
