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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    auto t = s;
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == '#') {
                REP(k, 4) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    t[ni][nj] = '#';
                }
            }
        }
    }
    vector visited(h, vector<bool>(w, false));
    set<pair<int, int>> st;
    int ans = 0, cnt = 0;
    auto dfs = [&](auto &dfs, int i, int j) -> void {
        ++cnt;
        visited[i][j] = true;
        if (t[i][j] == '#') {
            st.insert({i, j});
            return;
        }
        REP(k, 4) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (visited[ni][nj]) continue;
            if (s[i][j] == '#') continue;
            dfs(dfs, ni, nj);
        }
    };
    REP(i, h) {
        REP(j, w) {
            if (visited[i][j]) continue;
            if (s[i][j] == '#') continue;
            dfs(dfs, i, j);
            chmax(ans, cnt);
            cnt = 0;
            for (auto [_i, _j] : st) {
                visited[_i][_j] = false;
            }
            st.clear();
        }
    }
    output(ans);
}
