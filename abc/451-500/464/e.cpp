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
    int h, w, q;
    cin >> h >> w >> q;
    vector<int> r(q), c(q);
    vector<char> x(q);
    REP(i, q) cin >> r[i] >> c[i] >> x[i];
    reverse(ALL(r));
    reverse(ALL(c));
    reverse(ALL(x));
    string tmp = "";
    REP(i, w) tmp += "#";
    vector<string> ans(h, tmp);
    REP(i, q) {
        if (ans[r[i] - 1][c[i] - 1] != '#') continue;
        ans[r[i] - 1][c[i] - 1] = x[i];
        queue<pair<int, int>> que;
        que.push({r[i] - 1, c[i] - 1});
        while (!que.empty()) {
            auto [a, b] = que.front();
            que.pop();
            REP(k, 4) {
                int ny = a + dy[k];
                int nx = b + dx[k];
                if (ny < 0 || nx < 0 || ny >= r[i] || nx >= c[i]) continue;
                if (ans[ny][nx] != '#') continue;
                ans[ny][nx] = x[i];
                que.push({ny, nx});
            }
        }
    }
    REP(i, h) {
        REP(j, w) {
            if (ans[i][j] == '#') {
                ans[i][j] = 'A';
            }
        }
    }
    REP(i, h) output(ans[i]);
}
