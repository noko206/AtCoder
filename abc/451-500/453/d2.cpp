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
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    int sy, sx, gy, gx;
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            if (s[i][j] == 'G') {
                gy = i;
                gx = j;
            }
        }
    }
    queue<tuple<int, int, int>> q;
    vector dist(h, vector(w, vector<int>(4, INF32)));
    REP(i, 4) dist[sy][sx][i] = 0;
    vector pre(h, vector(w, vector<tuple<int, int, int>>(4, {-1, -1, -1})));
    q.push({sy, sx, 0});
    // 進行方向
    // 0:上, 1:右, 2:下, 3:左
    while (!q.empty()) {
        auto [y, x, d] = q.front();
        q.pop();
        REP(i, 4) {
            if (s[y][x] == 'o' && i != d) continue;
            if (s[y][x] == 'x' && i == d) continue;
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (s[ny][nx] == '#') continue;
            if (chmin(dist[ny][nx][i], dist[y][x][d] + 1)) {
                q.push({ny, nx, i});
                pre[ny][nx][i] = {y, x, d};
                if (s[ny][nx] == 'G') {
                    while (!q.empty()) {
                        q.pop();
                    }
                    break;
                }
            }
        }
    }
    bool is_ok = false;
    REP(i, 4) {
        if (dist[gy][gx][i] != INF32) {
            is_ok = true;
        }
    }
    if (!is_ok) {
        output("No");
        return 0;
    }
    string ans = "";
    int y = gy, x = gx;
    int d;
    REP(i, 4) {
        if (dist[gy][gx][i] != INF32) {
            d = i;
        }
    }
    while (s[y][x] != 'S') {
        auto [py, px, pd] = pre[y][x][d];
        assert(py != -1 && px != -1 && pd != -1);
        if (py + 1 == y) {
            ans += "D";
        } else if (py - 1 == y) {
            ans += "U";
        } else if (px + 1 == x) {
            ans += "R";
        } else {
            ans += "L";
        }
        y = py;
        x = px;
        d = pd;
        // cout << y << ' ' << x << endl;
    }
    reverse(ALL(ans));
    output("Yes");
    output(ans);
}
