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
ll c;

struct S {
    int idx;
    ll val;
};

S op1(S a, S b) {
    if (c * a.idx + a.val <= c * b.idx + b.val) {
        return b;
    } else {
        return a;
    }
}

S op2(S a, S b) {
    if (-c * a.idx + a.val <= -c * b.idx + b.val) {
        return b;
    } else {
        return a;
    }
}

S e() {
    S tmp;
    tmp.idx = 0;
    tmp.val = -INF64;
    return tmp;
}

int main() {
    int n, m;
    cin >> n >> c >> m;
    vector<ll> dp(n, -INF64);
    segtree<S, op1, e> seg1(n);
    seg1.set(0, {0, 0});
    segtree<S, op2, e> seg2(n);
    seg2.set(0, {0, 0});
    dp[0] = 0;
    REP(i, m) {
        int t;
        ll p;
        cin >> t >> p;
        if (dp[t - 1] != -INF64) {
            dp[t - 1] += p;
        }
        // 左
        auto s1 = seg1.prod(0, t);
        chmax(dp[t - 1], -c * abs((t - 1) - s1.idx) + s1.val + p);
        // 右
        auto s2 = seg2.prod(t, n);
        chmax(dp[t - 1], -c * abs((t - 1) - s2.idx) + s2.val + p);
        // 更新
        s1.idx = t - 1;
        s1.val = dp[t - 1];
        seg1.set(t - 1, s1);
        seg2.set(t - 1, s1);
    }
    ll ans = 0;
    REP(i, n) chmax(ans, dp[i]);
    output(ans);
}
