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
    cin >> n;
    vector<int> x(n);
    REP(i, n) cin >> x[i];
    int l;
    cin >> l;
    vector<int> to(n);
    REP(i, n) {
        int ok = i;
        int ng = n;
        while (ng - ok != 1) {
            int mid = (ok + ng) / 2;
            if (x[mid] - x[i] <= l) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        to[i] = ok;
    }
    Doubling d(to);
    d.build();
    int q;
    cin >> q;
    vector<ll> ans(q);
    REP(i, q) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        ll ok = INF64;
        ll ng = 0;
        while (ok - ng != 1) {
            ll mid = (ok + ng) / 2;
            if (d.query(a, mid) >= b) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans[i] = ok;
    }
    REP(i, q) output(ans[i]);
}
