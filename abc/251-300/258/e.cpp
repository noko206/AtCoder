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
    int n, q, x;
    cin >> n >> q >> x;
    vector<int> w(n);
    REP(i, n) cin >> w[i];
    fenwick_tree<ll> ft(n * 2);
    REP(i, n * 2) ft.add(i, w[i % n]);
    ll sum = ft.sum(0, n);
    vector<ll> cnt(n);
    auto bs = [&](int ok, int ng, int x, int i) -> int {
        while (ok - ng != 1) {
            int mid = (ok + ng) / 2;
            if (ft.sum(i, mid + 1) >= x) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    };
    REP(i, n) {
        int ok = bs(n * 2, i - 1, x, i);
        if (ok == n * 2) {
            ll c = n - i;
            ll nokori = x - ft.sum(i, n);
            c += (nokori / sum) * n;
            nokori %= sum;
            c += bs(n, -1, nokori, 0) + 1;
            cnt[i] = c;
        } else {
            cnt[i] = ok - i + 1;
        }
    }
    vector<int> a(n);
    REP(i, n) a[i] = (i + cnt[i]) % n;
    Doubling d(a);
    d.build();
    vector<ll> ans(q);
    REP(i, q) {
        ll k;
        cin >> k;
        ans[i] = cnt[d.query(0, k - 1)];
    }
    REP(i, q) output(ans[i]);
}
