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
ll f(ll x, ll y) {
    ll ans = 0;
    ans += (x / 4) * (y / 2) * 8;
    // y部分のはみでた部分
    if (y % 2 == 1) {
        ans += (x / 4) * 4;
    }
    // x部分のはみでた部分
    if (x % 4 == 1) {
        ans += (y / 2) * 3;
    } else if (x % 4 == 2) {
        ans += (y / 2) * 6;
    } else if (x % 4 == 3) {
        ans += (y / 2) * 7;
    }
    // 角のはみでた部分
    if (y % 2 != 0 && x % 4 != 0) {
        if (x % 4 == 1) {
            ans += 2;
        } else if (x % 4 == 2) {
            ans += 3;
        } else if (x % 4 == 3) {
            ans += 3;
        }
    }
    return ans;
}

int main() {
    ll x, y, z, w;
    cin >> x >> y >> z >> w;
    ll a = x % 4;
    if (a < 0) a += 4;
    ll b = y % 2;
    if (b < 0) b += 2;
    ll c = z - (x - a);
    ll d = w - (y - b);
    assert(a >= 0 && b >= 0 && c >= 0 && d >= 0);
    ll ans = f(c, d) - f(a, d) - f(c, b) + f(a, b);
    output(ans);
}