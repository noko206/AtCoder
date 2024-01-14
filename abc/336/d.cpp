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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    // 左から
    vector<int> left(n);
    {
        int r = 0;
        REP(l, n) {
            if (r < l) r = l;
            while (r < n && a[r] >= r - l + 1) {
                ++r;
            }
            // [l, r)
            left[l] = r - 1;
        }
    }
    // 右から
    reverse(ALL(a));
    vector<int> right(n);
    {
        int r = 0;
        REP(l, n) {
            if (r < l) r = l;
            while (r < n && a[r] >= r - l + 1) {
                ++r;
            }
            // [l, r)
            right[l] = r - 1;
        }
    }
    reverse(ALL(right));
    REP(i, n) right[i] = (n - 1) - right[i];
    int ans = 0;
    REP(l, n) {
        int ok = l;
        int ng = min((left[l] - l) * 2 + l + 1, n);
        while (ng - ok != 1) {
            int tmp_r = (ok + ng) / 2;
            int r = tmp_r;
            if ((r - l) % 2 == 1) --r;
            int m = (l + r) / 2;
            if (right[r] <= m) {
                ok = tmp_r;
            } else {
                ng = tmp_r;
            }
        }
        int r = ok;
        chmax(ans, (r - l) / 2 + 1);
    }
    output(ans);
}
