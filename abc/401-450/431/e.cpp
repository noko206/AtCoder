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
using T = tuple<int, int, int, int>;  // 4つ目: from上, 右, 下, 左

const int dy[] = {-1, 0, 1, 0};  // to上, 右, 下, 左
const int dx[] = {0, 1, 0, -1};

int solve(int h, int w, const vector<string> s) {
    vector dp(h, vector<int>(w + 1, INF32));
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 0, 0, 3});
    vector cost(h, vector(w + 1, vector<int>(4, INF32)));  // 3つ目: from
    cost[0][0][3] = 0;
    while (!pq.empty()) {
        auto [c, y, x, from] = pq.top();
        pq.pop();
        // output(c, y, x, from);
        if (cost[y][x][from] < c) continue;
        REP(to, 4) {
            int ny = y + dy[to];
            int nx = x + dx[to];
            if ((ny < 0 || nx < 0 || ny >= h || nx >= w) &&
                !(ny == h - 1 && nx == w)) {
                continue;
            }
            if (to == from) continue;  // 反射は考えない
            int next_from = (to + 2) % 4;
            int plus_cost = 1;
            if (s[y][x] == 'A') {
                if (next_from == from) {
                    plus_cost = 0;
                }
            } else if (s[y][x] == 'B') {
                // memo: 上, 右, 下, 左
                if ((from == 3 && next_from == 0) ||
                    (from == 0 && next_from == 3) ||
                    (from == 2 && next_from == 1) ||
                    (from == 1 && next_from == 2)) {
                    plus_cost = 0;
                }
            } else {
                // memo: 上, 右, 下, 左
                if ((from == 3 && next_from == 2) ||
                    (from == 0 && next_from == 1) ||
                    (from == 2 && next_from == 3) ||
                    (from == 1 && next_from == 0)) {
                    plus_cost = 0;
                }
            }
            if (chmin(cost[ny][nx][next_from], c + plus_cost) &&
                !(ny == h - 1 && nx == w)) {
                pq.push({c + plus_cost, ny, nx, next_from});
            }
        }
    }
    return cost[h - 1][w][3];  // from左しかありえない
}

int main() {
    int t;
    cin >> t;
    vector<int> ans(t);
    REP(i, t) {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        REP(j, h) cin >> s[j];
        ans[i] = solve(h, w, s);
    }
    REP(i, t) output(ans[i]);
}
