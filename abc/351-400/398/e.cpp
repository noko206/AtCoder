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
int main() {
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<int> depth(n, 0);
    auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
        if (p != -1) {
            depth[v] = depth[p] + 1;
        }
        for (auto u : to[v]) {
            if (u != p) {
                dfs(dfs, u, v);
            }
        }
    };
    dfs(dfs);
    vector<int> odd, even;
    REP(i, n) {
        if (depth[i] % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    vector linked(n, vector<bool>(n, false));
    REP(v, n) {
        for (auto u : to[v]) {
            linked[v][u] = true;
            linked[u][v] = true;
        }
    }
    queue<pair<int, int>> q;
    for (auto v : odd) {
        for (auto u : even) {
            assert(v != u);
            if (linked[v][u]) continue;
            if (v < u) {
                q.push({v, u});
            } else {
                q.push({u, v});
            }
        }
    }
    if (q.size() % 2 == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
        auto [i, j] = q.front();
        q.pop();
        cout << i + 1 << ' ' << j + 1 << endl;
    }
    while (true) {
        int i, j;
        cin >> i >> j;
        if (i == -1 && j == -1) {
            return 0;
        }
        --i, --j;
        linked[i][j] = true;
        linked[j][i] = true;
        while (true) {
            auto [v, u] = q.front();
            q.pop();
            if (linked[v][u]) continue;
            cout << v + 1 << ' ' << u + 1 << endl;
            break;
        }
    }
}
