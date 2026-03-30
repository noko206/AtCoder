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
using mint = modint;

int main() {
    ll k, m;
    cin >> k >> m;
    vector<ll> c(k), l(k);
    REP(i, k) cin >> c[i] >> l[i];
    ll amari = 0;
    {
        ll sum = 0;
        REP(i, k) sum += l[i];
        REP(i, k) {
            sum -= l[i];
            ll value = c[i] * (pow_mod(10LL, l[i], 9 * m) - 1) / 9;
            value %= m;
            value *= pow_mod(10LL, sum, m);
            value %= m;
            amari += value;
            amari %= m;
        }
    }
    vector<ll> sub(k, 0);
    {
        int cnt = 0;
        RREP(i, k - 1) {
            ll value = cnt == 0 ? 0 : pow(10, cnt - 1);
            REP(j, min(l[i], 10LL)) {
                value *= 10;
                value += c[i];
                ++cnt;
                if (value >= 1000000000) break;
            }
            sub[i] = min(value, amari);
            amari -= sub[i];
            if (amari == 0) break;
        }
        if (amari != 0) {
            return 0;
        }
    }
    ll ans = 0;
    ll sum = 0;
    REP(i, k) sum += l[i];
    int mod = 10007;
    REP(i, k) {
        sum -= l[i];
        ll value = c[i] * (pow_mod(10LL, l[i], 9 * mod) - 1) / 9;
        value %= mod;
        value *= pow_mod(10LL, sum, mod);
        value %= mod;
        value -= sub[i];
        if (value < 0) {
            value += mod;
        }
        value *= inv_mod(m, mod);
        value %= mod;
        ans += value;
        ans %= mod;
    }
    output(ans);
}
