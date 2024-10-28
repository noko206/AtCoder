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
struct Doubling {
   public:
    Doubling(int n) : n(n), dp(61, vector<int>(n)) {
        for (int i = 0; i < n; ++i) {
            dp[0][i] = i;
        }
    };

    Doubling(const vector<int> &a)
        : n(a.size()), dp(61, vector<int>(a.size())) {
        dp[0] = a;
    };

    // 0-indexed
    void add_edge(int v, int u) { dp[0][v] = u; }

    void build() {
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j] = dp[i][dp[i][j]];
            }
        }
    }

    // 0-indexed
    int query(int x, ll y) {
        int ans = x;
        for (int i = 0; i < 61; ++i) {
            if (y & (1LL << i)) {
                ans = dp[i][ans];
            }
        }
        return ans;
    }

   private:
    int n;
    vector<vector<int>> dp;
};

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n);
    REP(i, n) cin >> p[i], --p[i];
    vector<bool> seen(n, false);
    vector<int> siz(n);
    REP(v, n) {
        if (seen[v]) continue;
        vector<int> cycle;
        int u = v;
        while (!seen[u]) {
            seen[u] = true;
            cycle.push_back(u);
            u = p[u];
        }
        for (auto u : cycle) {
            siz[u] = cycle.size();
        }
    }
    Doubling d(p);
    d.build();
    vector<int> ans(n);
    REP(v, n) { ans[v] = d.query(v, pow_mod(2, k, siz[v])) + 1; }
    output(ans);
}