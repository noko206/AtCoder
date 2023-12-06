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
bool ok[1500][1500][2];
string s[1500];
int dist[1500][1500];

int main() {
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    --ax, --ay, --bx, --by;
    REP(i, n) cin >> s[i];
    REP(i, n) REP(j, n) dist[i][j] = INF32;
    dist[ax][ay] = 0;
    queue<int> q;
    q.push(ax * n + ay);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int vx = v / n;
        int vy = v % n;
        // 右上
        REP(i, 2) ok[vx][vy][i] = true;
        REP(i, 1, n) {
            int ux = vx + i;
            int uy = vy - i;
            if (ux < 0 || uy < 0 || ux >= n || uy >= n) break;
            if (s[ux][uy] == '#') break;
            if (ok[ux][uy][0]) break;
            if (chmin(dist[ux][uy], dist[vx][vy] + 1)) {
                q.push(ux * n + uy);
                ok[ux][uy][0] = true;
            }
        }
        // 右下
        REP(i, 1, n) {
            int ux = vx + i;
            int uy = vy + i;
            if (ux < 0 || uy < 0 || ux >= n || uy >= n) break;
            if (s[ux][uy] == '#') break;
            if (ok[ux][uy][1]) break;
            if (chmin(dist[ux][uy], dist[vx][vy] + 1)) {
                q.push(ux * n + uy);
                ok[ux][uy][1] = true;
            }
        }
        // 左下
        REP(i, 1, n) {
            int ux = vx - i;
            int uy = vy + i;
            if (ux < 0 || uy < 0 || ux >= n || uy >= n) break;
            if (s[ux][uy] == '#') break;
            if (ok[ux][uy][0]) break;
            if (chmin(dist[ux][uy], dist[vx][vy] + 1)) {
                q.push(ux * n + uy);
                ok[ux][uy][0] = true;
            }
        }
        // 左上
        REP(i, 1, n) {
            int ux = vx - i;
            int uy = vy - i;
            if (ux < 0 || uy < 0 || ux >= n || uy >= n) break;
            if (s[ux][uy] == '#') break;
            if (ok[ux][uy][1]) break;
            if (chmin(dist[ux][uy], dist[vx][vy] + 1)) {
                q.push(ux * n + uy);
                ok[ux][uy][1] = true;
            }
        }
        if (dist[bx][by] != INF32) break;
    }
    output(dist[bx][by] == INF32 ? -1 : dist[bx][by]);
}
