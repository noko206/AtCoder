// clang-format off
#include <bits/stdc++.h>
using namespace std;
// #if __has_include(<atcoder/all>)
// #include <atcoder/all>
// using namespace atcoder;
// #endif

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
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

ll m;

ll solve(int n, vector<int> c, vector<ll> f) {
    ll bunbo = 1;
    int sum = 0;
    REP(i, n) {
        bunbo *= f[c[i]];
        bunbo %= m;
        sum += c[i];
    }
    ll mod = m * bunbo;
    __int128_t ans = 1;
    REP(x, 2, sum + 1) {
        ans *= x;
        ans %= mod;
    }
    cout << endl << ans << ":" << bunbo << endl;
    ll ans_ = (ll)(ans / bunbo);
    return ans_;
}

int main() {
    int t;
    cin >> t >> m;
    vector<ll> ans(t);
    vector<ll> f(5001);
    f[0] = 1;
    REP(i, 1, 5001) { f[i] = (f[i - 1] * i) % m; }
    REP(i, t) {
        int n;
        cin >> n;
        vector<int> c(n);
        REP(i, n) cin >> c[i];
        ans[i] = solve(n, c, f);
    }
    REP(i, t) cout << ans[i] << endl;
}
