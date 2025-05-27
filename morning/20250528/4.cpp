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
const int dr[] = {0, 1};
const int dc[] = {1, 0};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    vector dist(h, vector<int>(w, INF32));
    dist[0][0] = s[0][0] == '.' ? 0 : 1;
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop_front();
        REP(i, 2) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= h || nc >= w) continue;
            if (s[r][c] == s[nr][nc]) {
                if (chmin(dist[nr][nc], dist[r][c])) {
                    q.push_front({nr, nc});
                }
            } else {
                if (chmin(dist[nr][nc], dist[r][c] + 1)) {
                    q.push_back({nr, nc});
                }
            }
        }
    }
    int ans = dist[h - 1][w - 1];
    if (s[h - 1][w - 1] == '#') {
        ++ans;
        if (s[0][0] == s[h - 1][w - 1]) {
            --ans;
        }
    }
    output(ans);
}
