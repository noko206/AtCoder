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
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h) cin >> a[i];
    vector dist(h, vector(w, vector<int>(2, INF32)));
    int sy, sx;
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == 'S') {
                sy = i;
                sx = j;
            }
        }
    }
    dist[sy][sx][0] = 0;
    queue<tuple<int, int, int>> q;
    q.push({sy, sx, 0});
    while (!q.empty()) {
        auto [y, x, f] = q.front();
        q.pop();
        REP(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (a[ny][nx] == '#') continue;
            if (f == 0 && a[ny][nx] == 'x') continue;
            if (f == 1 && a[ny][nx] == 'o') continue;
            if (a[ny][nx] == '?') {
                if (chmin(dist[ny][nx][(f + 1) % 2], dist[y][x][f] + 1)) {
                    q.push({ny, nx, (f + 1) % 2});
                }
            } else {
                if (chmin(dist[ny][nx][f], dist[y][x][f] + 1)) {
                    q.push({ny, nx, f});
                }
            }
        }
    }
    int gy, gx;
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == 'G') {
                gy = i;
                gx = j;
            }
        }
    }
    int ans = min(dist[gy][gx][0], dist[gy][gx][1]);
    output(ans == INF32 ? -1 : ans);
}
