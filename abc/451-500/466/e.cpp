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
template <class T> struct CumulativeSum {
   public:
    CumulativeSum(int n) : n(n), data(n + 1, 0) {};
    CumulativeSum(const vector<T>& v) : n((int)v.size()) {
        data.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            data[i + 1] = v[i];
        }
    };

    void add(int idx, T x) {
        assert(0 <= idx && idx < n);
        data[idx + 1] += x;
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            data[i + 1] += data[i];
        }
    }

    // [l, r)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return data[r] - data[l];
    }

   private:
    int n;
    vector<T> data;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    CumulativeSum<ll> cs(n);
    REP(i, n) cs.add(i, b[i] - a[i]);
    cs.build();
    vector<ll> sum;
    ll cnt = 0;
    REP(i, n) {
        if (cnt == 0) {
            cnt = cs.sum(i, i + 1);
        } else if (cnt > 0) {
            if (cs.sum(i, i + 1) >= 0) {
                cnt += cs.sum(i, i + 1);
            } else {
                sum.push_back(cnt);
                cnt = cs.sum(i, i + 1);
            }
        } else {
            if (cs.sum(i, i + 1) <= 0) {
                cnt += cs.sum(i, i + 1);
            } else {
                sum.push_back(cnt);
                cnt = cs.sum(i, i + 1);
            }
        }
    }
    if (cnt != 0) sum.push_back(cnt);
    int m = sum.size();
    vector dp(m + 1, vector(k + 1, vector<ll>(2, -INF64)));
    dp[0][0][0] = 0;
    REP(i, m) {
        REP(j, k + 1) {
            chmax(dp[i + 1][j][0], dp[i][j][0]);
            chmax(dp[i + 1][j][0], dp[i][j][1]);
            if (j + 1 <= k) {
                chmax(dp[i + 1][j + 1][1], dp[i][j][0] + sum[i]);
            }
            chmax(dp[i + 1][j][1], dp[i][j][1] + sum[i]);
        }
    }
    ll ans = 0;
    REP(i, k + 1) {
        chmax(ans, dp[m][i][0]);
        chmax(ans, dp[m][i][1]);
    }
    REP(i, n) ans += a[i];
    output(ans);
}
