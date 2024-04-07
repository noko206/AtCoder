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
    int n;
    cin >> n;
    vector e(h, vector<int>(w, 0));
    REP(i, n) {
        int r, c, _e;
        cin >> r >> c >> _e;
        --r, --c;
        e[r][c] = _e;
    }
    int si, sj;
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    if (e[si][sj] == 0) {
        output("No");
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({si, sj});
    vector seen(h, vector<bool>(w, false));
    seen[si][sj] = true;
    while (!q.empty()) {
        auto [si, sj] = q.front();
        q.pop();
        vector ok(h, vector<int>(w, -1));
        ok[si][sj] = e[si][sj];
        queue<pair<int, int>> que;
        que.push({si, sj});
        while (!que.empty()) {
            auto [y, x] = que.front();
            que.pop();
            if (a[y][x] == 'T') {
                output("Yes");
                return 0;
            }
            if (e[y][x] > 0 && !seen[y][x]) {
                q.push({y, x});
                seen[y][x] = true;
            }
            if (ok[y][x] == 0) continue;
            REP(i, 4) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if (a[ny][nx] == '#') continue;
                if (ok[ny][nx] >= 0) continue;
                ok[ny][nx] = ok[y][x] - 1;
                que.push({ny, nx});
            }
        }
    }
    output("No");
    return 0;
}
