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
template <typename T> T binomial(int n, int k) {
    if (k < 0 || n < k) return 0;
    static vector<T> fact;
    static vector<T> ifact;
    if ((int)fact.size() < n + 1) {
        int pos = (int)fact.size();
        fact.resize(n + 1);
        for (int i = pos; i <= n; ++i) {
            if (i > 0) {
                fact[i] = i * fact[i - 1];
            } else {
                fact[i] = 1;
            }
        }
    }
    int mx = max(k, n - k);
    if ((int)ifact.size() < mx + 1) {
        int pos = (int)ifact.size();
        ifact.resize(mx + 1);
        ifact[mx] = 1 / fact[mx];
        for (int i = mx - 1; i >= pos; --i) {
            ifact[i] = (i + 1) * ifact[i + 1];
        }
    }
    return fact[n] * ifact[k] * ifact[n - k];
}

using mint = modint1000000007;

int main() {
    int n, r;
    cin >> n >> r;
    auto ans = binomial<mint>(n, r);
    output(ans.val());
}
