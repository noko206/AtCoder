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
const int dy[] = {-1, 0, 1, 0};  // 上0, 右1, 下2, 左3
const int dx[] = {0, 1, 0, -1};

pair<bool, string> solve(int n, int sa, int sb) {
    int a = sa, b = sb;
    // 上
    int u = a / 2;
    a %= 2;
    // 左
    int l = b / 2;
    b %= 2;
    // 下
    int d = (n - sa - 1) / 2;
    int h = n - d * 2 - u * 2;
    // 右
    int r = (n - sb - 1) / 2;
    int w = n - r * 2 - l * 2;
    vector to(n, vector<int>(n, -1));
    auto dfs = [&](auto& dfs, int y = 0, int x = 0, int cnt = 0) -> bool {
        if (y == h - 1 && x == w - 1) {
            if (cnt == h * w - 2) {
                return true;
            } else {
                return false;
            }
        }
        REP(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (ny == a && nx == b) continue;
            if (to[ny + u * 2][nx + l * 2] != -1) continue;
            to[y + u * 2][x + l * 2] = i;
            if (dfs(dfs, ny, nx, cnt + 1)) {
                return true;
            }
            to[y + u * 2][x + l * 2] = -1;
        }
        return false;
    };
    if (!dfs(dfs)) return {false, ""};
    // 上
    int posY = 0, posX = 0;
    REP(i, u) {
        REP(j, n - 1) {
            to[posY][posX] = 1;
            ++posX;
        }
        to[posY][posX] = 2;
        ++posY;
        REP(j, n - 1) {
            to[posY][posX] = 3;
            --posX;
        }
        to[posY][posX] = 2;
        ++posY;
    }
    // 左
    REP(i, l) {
        REP(j, n - u * 2 - 1) {
            to[posY][posX] = 2;
            ++posY;
        }
        to[posY][posX] = 1;
        ++posX;
        REP(j, n - u * 2 - 1) {
            to[posY][posX] = 0;
            --posY;
        }
        to[posY][posX] = 1;
        ++posX;
    }
    // dfsで探索したルートを辿る
    while (to[posY][posX] != -1) {
        int next = to[posY][posX];
        posY += dy[next];
        posX += dx[next];
    }
    to[posY][posX] = 1;
    ++posX;
    // 右
    REP(i, r) {
        REP(j, h - 1) {
            to[posY][posX] = 0;
            --posY;
        }
        to[posY][posX] = 1;
        ++posX;
        REP(j, h - 1) {
            to[posY][posX] = 2;
            ++posY;
        }
        to[posY][posX] = 1;
        ++posX;
    }
    // 下
    REP(i, d) {
        REP(j, w + r * 2 - 1) {
            to[posY][posX] = 3;
            --posX;
        }
        to[posY][posX] = 2;
        ++posY;
        REP(j, w + r * 2 - 1) {
            to[posY][posX] = 1;
            ++posX;
        }
        to[posY][posX] = 2;
        ++posY;
    }
    string ans = "";
    posY = 0, posX = 0;
    while (!(posY == n - 1 && posX == n - 1)) {
        int next = to[posY][posX];
        if (next == 0) {
            ans += 'U';
        } else if (next == 1) {
            ans += 'R';
        } else if (next == 2) {
            ans += 'D';
        } else {
            ans += 'L';
        }
        posY += dy[next];
        posX += dx[next];
    }
    if (ans.length() != n * n - 2) {
        return {false, ""};
    }
    return {true, ans};
}

int main() {
    int t;
    cin >> t;
    vector<pair<bool, string>> ans(t);
    REP(i, t) {
        int n, a, b;
        cin >> n >> a >> b;
        --a, --b;
        ans[i] = solve(n, a, b);
    }
    for (auto [is_ok, str] : ans) {
        if (is_ok) {
            output("Yes");
            output(str);
        } else {
            output("No");
        }
    }
}
