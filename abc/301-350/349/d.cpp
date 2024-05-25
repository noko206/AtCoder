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
int main() {
    ll l, r;
    cin >> l >> r;
    vector<pair<ll, ll>> ans;
    if (l == 0) {
        ll tmp = r;
        ll ansR = 1;
        while (tmp > 0) {
            tmp /= 2;
            ansR *= 2;
        }
        ansR /= 2;
        assert(ansR <= r);
        ans.emplace_back(l, ansR);
        l = ansR;
        if (l == r) {
            output(ans.size());
            for (auto [x, y] : ans) {
                output(x, y);
            }
            return 0;
        }
    }
    while (true) {
        ll tmp = l;
        ll p = 1;
        while (tmp % 2 == 0) {
            tmp /= 2;
            p *= 2;
        }
        ll ansR = p * (tmp + 1);
        ll tmpR = ansR;
        while (ansR > r) {
            assert(tmpR % 2 == 0);
            tmpR /= 2;
            p /= 2;
            tmp *= 2;
            ansR = p * (tmp + 1);
        }
        ans.emplace_back(l, ansR);
        if (r == ansR) break;
        l = ansR;
    }
    output(ans.size());
    for (auto [x, y] : ans) {
        output(x, y);
    }
}
