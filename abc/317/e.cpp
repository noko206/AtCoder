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
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == '>') {
                REP(k, j + 1, w) {
                    if (a[i][k] == '.' || a[i][k] == '!') {
                        a[i][k] = '!';
                    } else {
                        break;
                    }
                }
            } else if (a[i][j] == 'v') {
                REP(k, i + 1, h) {
                    if (a[k][j] == '.' || a[k][j] == '!') {
                        a[k][j] = '!';
                    } else {
                        break;
                    }
                }
            } else if (a[i][j] == '<') {
                RREP(k, j - 1, 0) {
                    if (a[i][k] == '.' || a[i][k] == '!') {
                        a[i][k] = '!';
                    } else {
                        break;
                    }
                }
            } else if (a[i][j] == '^') {
                RREP(k, i - 1, 0) {
                    if (a[k][j] == '.' || a[k][j] == '!') {
                        a[k][j] = '!';
                    } else {
                        break;
                    }
                }
            }
        }
    }
    int si, sj, gi, gj;
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({si, sj});
    vector dist(h, vector<int>(w, INF32));
    dist[si][sj] = 0;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        REP(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (a[ny][nx] == '.' || a[ny][nx] == 'G') {
                if (chmin(dist[ny][nx], dist[y][x] + 1)) {
                    q.push({ny, nx});
                }
            }
        }
    }
    output(dist[gi][gj] == INF32 ? -1 : dist[gi][gj]);
}
