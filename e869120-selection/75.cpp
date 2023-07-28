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
template <class T, T (*merge)(T, T), T (*add_root)(T), T (*e)()>
struct Rerooting {
   public:
    Rerooting(int n) : n(n), to(n), dp_e(n), dp_v(n){};

    // 有向辺u->vを張る
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        to[u].push_back(v);
    }

    void build() {
        dfs();
        dfs_all();
    }

    // ある頂点のDP値
    T get_v(int idx) {
        assert(0 <= idx && idx < n);
        return dp_v[idx];
    }

    // ある頂点から辺で結ばれている各頂点を根とする部分木のDP値
    vector<T> get_e(int idx) {
        assert(0 <= idx && idx < n);
        return dp_e[idx];
    }

   private:
    int n;
    vector<T> dp_v;
    vector<vector<T>> dp_e;
    vector<vector<int>> to;

    // 木DP
    T dfs(int v = 0, int p = -1) {
        T dp_x = e();
        int deg = (int)to[v].size();
        dp_e[v] = vector<T>(deg, e());
        for (int i = 0; i < deg; ++i) {
            int u = to[v][i];
            if (u == p) continue;
            dp_e[v][i] = dfs(u, v);
            dp_x = merge(dp_x, dp_e[v][i]);
        }
        return add_root(dp_x);
    }

    // 残りの部分木に対応するDP値を計算
    void dfs_all(int v = 0, const T &dp_p = e(), int p = -1) {
        int deg = (int)to[v].size();
        for (int i = 0; i < deg; ++i) {
            if (to[v][i] == p) dp_e[v][i] = dp_p;
        }
        vector<T> dp_l(deg + 1, e()), dp_r(deg + 1, e());
        for (int i = 0; i < deg; ++i) {
            dp_l[i + 1] = merge(dp_l[i], dp_e[v][i]);
        }
        for (int i = deg - 1; i >= 0; --i) {
            dp_r[i] = merge(dp_r[i + 1], dp_e[v][i]);
        }
        dp_v[v] = add_root(dp_l[deg]);
        for (int i = 0; i < deg; ++i) {
            int u = to[v][i];
            if (u == p) continue;
            dfs_all(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};

using mint = modint1000000007;

int merge(int x, int y) { return x + y; }
int add_root(int x) { return x + 1; }
int e() { return 0; }

int main() {
    int n;
    cin >> n;
    Rerooting<int, merge, add_root, e> graph(n);
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph.add_edge(a, b);
        graph.add_edge(b, a);
    }
    graph.build();
    mint ans = 0;
    REP(i, n) {
        mint ng = 1;
        for (auto v : graph.get_e(i)) {
            ng += pow_mod(2, v, 1000000007) - 1;
        }
        ans += pow_mod(2, n - 1, 1000000007) - ng;
    }
    ans /= pow_mod(2, n, 1000000007);
    output(ans.val());
}
