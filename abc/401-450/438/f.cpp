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
// 最長共通祖先 (Lowest Common Ancestor)
struct LCA {
   public:
    LCA(const vector<vector<int>>& G, int root = 0) { init(G, root); }

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

   private:
    vector<vector<int>> parent;
    vector<int> dist;

    void init(const vector<vector<int>>& G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e != p) dfs(G, e, v, d + 1);
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    LCA lca(to);
    vector<int> w(n, 1);
    auto dfs = [&](auto& dfs, int v = 0, int p = -1) -> int {
        for (int u : to[v]) {
            if (u == p) continue;
            w[v] += dfs(dfs, u, v);
        }
        return w[v];
    };
    dfs(dfs);
    ll ans = 1;  // (0, 0) は条件を満たす
    {
        ll sum = (ll)n * (n - 1) / 2;
        for (int v : to[0]) {
            sum -= (ll)w[v] * (w[v] - 1) / 2;
        }
        ans += sum;
    }
    auto dist = [&](int l, int r) -> int {
        return w[l] + w[r] - 2 * w[lca.query(l, r)];
    };
    int l = 0, r = 0;
    int l_ = -1, r_ = -1;
    REP(v, 1, n) {
        if (dist(v, l) + dist(l, r) == dist(v, r)) {
            l = v;
            if (l_ == -1) {
                for (int u : to[0]) {
                    if (dist(l, u) + dist(u, 0) == dist(l, 0)) {
                        l_ = u;
                        break;
                    }
                }
            }
        } else if (dist(l, r) + dist(r, v) == dist(l, v)) {
            r = v;
            if (r_ == -1) {
                for (int u : to[0]) {
                    if (dist(r, u) + dist(u, 0) == dist(r, 0)) {
                        r_ = u;
                        break;
                    }
                }
            }
        } else if (dist(l, v) + dist(v, r) != dist(l, r)) {
            break;
        }
        ll sumL = w[l], sumR = w[r];
        if (l == 0) {
            assert(r_ != -1);
            sumL -= w[r_];
        }
        if (r == 0) {
            assert(l_ != -1);
            sumR -= w[l_];
        }
        ans += sumL * sumR;
    }
    output(ans);
}
