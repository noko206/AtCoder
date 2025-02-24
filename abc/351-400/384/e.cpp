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

using P = pair<ll, pair<int, int>>;

int main() {
    int h, w, x;
    cin >> h >> w >> x;
    int p, q;
    cin >> p >> q;
    --p, --q;
    vector s(h, vector<ll>(w));
    REP(i, h) REP(j, w) cin >> s[i][j];
    vector seen(h, vector<bool>(w, false));
    priority_queue<P, vector<P>, greater<P>> pq;
    seen[p][q] = true;
    REP(i, 4) {
        int y = p + dy[i];
        int x = q + dx[i];
        if (y < 0 || y >= h || x < 0 || x >= w) continue;
        seen[y][x] = true;
        pq.push({s[y][x], {y, x}});
    }
    ll strong = s[p][q];
    while (!pq.empty()) {
        if (strong % x == 0) {
            if (pq.top().first >= strong / x) {
                break;
            }
        } else {
            if (pq.top().first > strong / x) {
                break;
            }
        }
        auto [v, pos] = pq.top();
        pq.pop();
        strong += v;
        auto [y, x] = pos;
        REP(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (seen[ny][nx]) continue;
            seen[ny][nx] = true;
            pq.push({s[ny][nx], {ny, nx}});
        }
    }
    output(strong);
}
