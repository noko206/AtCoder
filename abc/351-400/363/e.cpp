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
using P = pair<int, pair<int, int>>;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector a(h, vector<int>(w));
    REP(i, h) REP(j, w) cin >> a[i][j];
    priority_queue<P, vector<P>, greater<P>> pq;
    REP(i, h) REP(j, w) pq.push({a[i][j], {i, j}});
    vector sunk(h, vector<bool>(w, false));
    vector<int> ans(y);
    int sum = h * w;
    auto dfs = [&](auto &dfs, int y, int x, int border) -> void {
        if (sunk[y][x]) return;
        sunk[y][x] = true;
        --sum;
        REP(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (a[ny][nx] <= border) {
                dfs(dfs, ny, nx, border);
            }
        }
    };
    REP(border, 1, y + 1) {
        while (!pq.empty() && pq.top().first <= border) {
            auto [height, pos] = pq.top();
            auto [y, x] = pos;
            bool is_ok = false;
            REP(i, 4) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                    is_ok = true;
                    break;
                }
                if (sunk[ny][nx]) {
                    is_ok = true;
                    break;
                }
            }
            if (is_ok) {
                dfs(dfs, y, x, border);
            }
            pq.pop();
        }
        ans[border - 1] = sum;
    }
    REP(i, y) output(ans[i]);
}
