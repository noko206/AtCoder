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
ll solve(ll c, ll d) {
    int keta = 0;
    ll tmp = c + 1;
    while (tmp > 0) {
        ++keta;
        tmp /= 10;
    }
    int keta_max = 0;
    tmp = c + d;
    while (tmp > 0) {
        ++keta_max;
        tmp /= 10;
    }
    // メイン
    ll ans = 0;
    REP(k, keta, keta_max + 1) {
        // セットアップ
        ll left = c;
        REP(i, k) left *= 10;
        // 下から
        ll bottom = powl(10, k - 1);
        if (k == keta) {
            bottom = c + 1;
        }
        bottom += left;
        ll bottom_sqrt = (ll)sqrtl(bottom);
        REP(i, -1, 2) {
            if (bottom <= (bottom_sqrt + i) * (bottom_sqrt + i)) {
                bottom_sqrt += i;
                break;
            }
        }
        // 上から
        ll top = powl(10, k) - 1;
        if (k == keta_max) {
            top = c + d;
        }
        top += left;
        ll top_sqrt = (ll)sqrtl(top);
        RREP(i, 1, -1) {
            if (top >= (top_sqrt + i) * (top_sqrt + i)) {
                top_sqrt += i;
                break;
            }
        }
        // 答え
        ans += max(top_sqrt - bottom_sqrt + 1, 0LL);
        // output("---");
        // output(bottom, bottom_sqrt);
        // output(top, top_sqrt);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<ll> ans(t);
    REP(i, t) {
        ll c, d;
        cin >> c >> d;
        ans[i] = solve(c, d);
    }
    REP(i, t) output(ans[i]);
}
