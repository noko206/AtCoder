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
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const string snuke = "snuke";

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    vector<vector<vector<int>>> dist(
        h, vector<vector<int>>(w, vector<int>(5, INF32)));
    queue<pair<pair<int, int>, string>> q;
    if (s[0][0] == 's') dist[0][0][1] = 0;
    q.push({{0, 0}, {s[0][0]}});
    while (!q.empty()) {
        auto [p, c] = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        REP(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (s[ny][nx] != snuke[c.length()]) continue;
            string nc = "";
            if (c.length() <= 3) {
                nc = c;
                nc += {snuke[c.length()]};
            }
            if (chmin(dist[ny][nx][nc.length() % 5],
                      dist[y][x][c.length()] + 1)) {
                q.push({{ny, nx}, nc});
            }
        }
    }
    bool is_ok = false;
    REP(i, 5) {
        if (dist[h - 1][w - 1][i] != INF32) is_ok = true;
    }
    YesNo(is_ok);
    // REP(i, 5) {
    //     REP(j, h) {
    //         REP(k, w) { cout << dist[j][k][i] << ' '; }
    //         cout << endl;
    //     }
    //     output("---");
    // }
}
