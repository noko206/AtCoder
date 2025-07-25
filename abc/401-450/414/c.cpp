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
vector<int> f(ll x) {
    vector<int> ans;
    while (x > 0) {
        ans.push_back(x % 10);
        x /= 10;
    }
    reverse(ALL(ans));
    return ans;
}

int main() {
    int a;
    ll n;
    cin >> a >> n;
    ll ans = 0;
    REP(k, 25) {
        ll start = powl(10, k);
        ll end = powl(10, k + 1);
        bool is_break = false;
        for (ll x = start; x < end; ++x) {
            auto sep = f(x);
            int len = sep.size();
            // 奇数桁
            ll y = x;
            RREP(i, len - 2) {
                y *= 10;
                y += sep[i];
            }
            if (y > n) {
                is_break = true;
                break;
            }
            string z = "";
            ll tmpy = y;
            while (y > 0) {
                z += (char)((y % a) + '0');
                y /= a;
            }
            auto tmp = z;
            reverse(ALL(tmp));
            if (z == tmp) {
                ans += tmpy;
            }
        }
        if (is_break) break;
        for (ll x = start; x < end; ++x) {
            auto sep = f(x);
            int len = sep.size();
            // 偶数桁
            ll y = x;
            RREP(i, len - 1) {
                y *= 10;
                y += sep[i];
            }
            if (y > n) {
                is_break = true;
                break;
            };
            string z = "";
            ll tmpy = y;
            while (y > 0) {
                z += (char)((y % a) + '0');
                y /= a;
            }
            auto tmp = z;
            reverse(ALL(tmp));
            if (z == tmp) {
                ans += tmpy;
            }
        }
        if (is_break) break;
    }
    output(ans);
}
