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
template <typename S> vector<int> manacher(S s, bool calc_even = true) {
    if (calc_even) {
        int n = (int)s.size();
        assert(n > 0);
        s.resize(2 * n - 1);
        for (int i = n - 1; i >= 0; i--) {
            s[2 * i] = s[i];
        }
        auto d = *min_element(begin(s), end(s));
        for (int i = 0; i < n - 1; i++) {
            s[2 * i + 1] = d;
        }
    }
    int n = (int)s.size();
    vector<int> rad(n);
    {
        int i = 0, j = 0;
        while (i < n) {
            while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
            rad[i] = j;
            int k = 1;
            while (i - k >= 0 && i + k < n && k + rad[i - k] < j) {
                rad[i + k] = rad[i - k];
                ++k;
            }
            i += k, j -= k;
        }
    }
    if (calc_even) {
        for (int i = 0; i < n; i++) {
            if (((i ^ rad[i]) & 1) == 0) rad[i]--;
        }
    } else {
        for (auto &&x : rad) x = 2 * x - 1;
    }
    return rad;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    string t = s;
    reverse(ALL(t));
    auto rad = manacher(t);
    int pos = 0;
    REP(i, rad.size()) {
        if (rad[i] == i + 1) {
            pos = i + 1;
        }
    }
    string ans = s;
    RREP(i, n - pos - 1) { ans += s[i]; }
    output(ans);
}
