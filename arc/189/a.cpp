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
vector<pair<int, int>> run_length_encode(const vector<int> &s) {
    vector<pair<int, int>> ans;
    int i = 0, j = 0, n = s.size();
    while (i < n) {
        while (j < n && s[i] == s[j]) {
            ++j;
        }
        ans.push_back({s[i], j - i});
        i = j;
    }
    return ans;
}

using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    auto e = run_length_encode(a);
    if (n % 2 == 0) {
        if (e[0].first != 1 || e[e.size() - 1].first != 0) {
            output(0);
            return 0;
        }
    } else {
        if (e[0].first != 1 || e[e.size() - 1].first != 1) {
            output(0);
            return 0;
        }
    }
    for (auto [num, cnt] : e) {
        if (cnt % 2 != 1) {
            output(0);
            return 0;
        }
    }
    // fact
    vector<mint> fact(n + 1), ifact(n + 1);
    fact[0] = 1;
    REP(i, 1, n + 1) { fact[i] = fact[i - 1] * i; }
    REP(i, n + 1) { ifact[i] = fact[i].inv(); }
    vector<mint> ffact(n + 1);
    ffact[0] = 1;
    ffact[1] = 1;
    REP(i, 2, n + 1) { ffact[i] = ffact[i - 2] * i; }
    // メイン処理
    mint ans = 1;
    int tot = 0;
    for (auto [num, cnt] : e) {
        ans *= ffact[max(0, cnt - 2)];
        ans *= ifact[cnt / 2];
        tot += cnt / 2;
    }
    ans *= fact[tot];
    output(ans.val());
}
