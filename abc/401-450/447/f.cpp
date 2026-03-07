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
bool visited[200000];

/** 参考：https://algo-logic.info/tree-diameter/ */
using Graph = vector<vector<int>>;

pair<int, int> dfs(const vector<vector<int>>& G, int u, int par) {
    // output(u);
    visited[u] = true;
    pair<int, int> ret = make_pair(0, u);
    if (G[u].size() == 1 && par != -1) return ret;
    for (auto e : G[u]) {
        if (e == par) continue;
        auto next = dfs(G, e, u);
        next.first += 1;
        ret = max(ret, next);
    }
    return ret;
}
int tree_diamiter(const vector<vector<int>>& G, int v) {
    pair<int, int> p = dfs(G, v, -1);
    pair<int, int> q = dfs(G, p.second, -1);
    return q.first + 1;
}

int solve(int n, const vector<int>& a, const vector<int>& b) {
    REP(i, n) visited[i] = false;
    vector<vector<int>> to(n);
    REP(i, n - 1) {
        to[a[i] - 1].push_back(b[i] - 1);
        to[b[i] - 1].push_back(a[i] - 1);
    }
    vector<vector<int>> to2(n);
    REP(i, n - 1) {
        if (to[a[i] - 1].size() >= 4 && to[b[i] - 1].size() >= 4) {
            to2[a[i] - 1].push_back(b[i] - 1);
            to2[b[i] - 1].push_back(a[i] - 1);
        }
    }
    REP(v, n) {
        if (to[v].size() >= 4) {
            for (int u : to[v]) {
                if (to[u].size() == 3) {
                    to2[v].push_back(u);
                    to2[u].push_back(v);
                }
            }
        }
    }
    int ans = 0;
    // 3to3を探す
    REP(v, n) {
        if (to[v].size() >= 2) {
            chmax(ans, 1);
        }
        if (to[v].size() != 3) continue;
        for (int u : to[v]) {
            if (to[u].size() == 3) {
                chmax(ans, 2);
            }
        }
    }
    REP(v, n) {
        if (visited[v]) continue;
        if (to[v].size() == 3) continue;
        chmax(ans, tree_diamiter(to2, v));
    }
    return ans;
}

int main() {
    int q;
    cin >> q;
    vector<int> ans(q);
    REP(i, q) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        REP(j, n - 1) cin >> a[j] >> b[j];
        ans[i] = solve(n, a, b);
    }
    REP(i, q) output(ans[i]);
}
