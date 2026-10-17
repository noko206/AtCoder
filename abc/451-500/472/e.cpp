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
pair<int, vector<int>> solve(int n, int m, vector<int> a, vector<int> b) {
    vector<vector<int>> to(n);
    REP(i, m) {
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);
    }
    vector<int> f(n, -1);
    auto dfs = [&](auto& dfs, int v = 0, int x = 0) -> void {
        if (f[v] != -1) return;
        f[v] = x;
        for (int u : to[v]) {
            dfs(dfs, u, (x + 1) % 2);
        }
    };
    dfs(dfs);
    int s = -1, g = -1;
    REP(v, n) {
        for (int u : to[v]) {
            if (f[v] == f[u]) {
                s = v;
                g = u;
            }
        }
    }
    vector<int> k;
    if (s == -1 && g == -1) {
        return make_pair(-1, k);
    }
    bool is_finished = false;
    vector<bool> visited(n, false);
    k.push_back(s + 1);
    auto dfs2 = [&](auto& dfs2, int v) -> void {
        if (is_finished) return;
        if (visited[v]) return;
        visited[v] = true;
        if (v == g) {
            is_finished = true;
            return;
        }
        for (int u : to[v]) {
            if (f[v] == f[u]) continue;
            k.push_back(u + 1);
            dfs2(dfs2, u);
            if (is_finished) return;
            k.pop_back();
        }
    };
    dfs2(dfs2, s);
    assert(k.size() >= 3 && k.size() % 2 == 1);
    return make_pair(k.size(), k);
}

int main() {
    int t;
    cin >> t;
    vector<int> k(t);
    vector<vector<int>> v(t);
    REP(i, t) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b(m);
        REP(j, m) cin >> a[j] >> b[j], --a[j], --b[j];
        auto [_k, _v] = solve(n, m, a, b);
        k[i] = _k;
        v[i] = _v;
    }
    REP(i, t) {
        output(k[i]);
        if (k[i] == -1) continue;
        output(v[i]);
    }
}
