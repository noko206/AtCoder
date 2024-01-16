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
template <class T> vector<vector<T>> matrix_mul(const vector<vector<T>> &a,
                                                const vector<vector<T>> &b) {
    vector<vector<T>> res(a.size(), vector<T>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

template <class T>
vector<vector<T>> matrix_pow(vector<vector<T>> a, long long n) {
    vector<vector<T>> res(a.size(), vector<T>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (n > 0) {
        if (n & 1) res = matrix_mul(a, res);
        a = matrix_mul(a, a);
        n >>= 1;
    }
    return res;
}

using mint = modint1000000007;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector a(n, vector<mint>(n));
    REP(i, n) {
        REP(j, n) {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    auto p = matrix_pow(a, k);
    mint ans = 0;
    REP(i, n) REP(j, n) ans += p[i][j];
    output(ans.val());
}
