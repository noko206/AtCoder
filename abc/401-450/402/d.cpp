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
typedef long double ld;
const long double eps = 1e-9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i], --a[i], --b[i];
    // メイン処理
    vector<pair<ld, ld>> pos(n);
    ld ini = 2.0 * M_PI / (ld)n;
    ld now = 0.0;
    REP(i, n) {
        pos[i] = {cos(now), sin(now)};
        now += ini;
    }
    vector<ld> rad;
    auto calc_rad = [&](int i) -> ld {
        auto [x1, y1] = pos[a[i]];
        auto [x2, y2] = pos[b[i]];
        ld r = (y2 - y1) / (x2 - x1);
        return abs(r) >= 3000 ? INF32 : r;
    };
    // 順番決定
    vector<ld> sorted_rad;
    REP(i, m) {
        ld tmp_rad = calc_rad(i);
        sorted_rad.emplace_back(tmp_rad);
    }
    sort(ALL(sorted_rad));
    output(sorted_rad);
    // run_length_encode的な
    vector<pair<ld, int>> encode;
    {
        ld r = sorted_rad[0];
        int cnt = 0;
        REP(i, m) {
            if (abs(r - sorted_rad[i]) < eps) {
                ++cnt;
                continue;
            }
            encode.emplace_back(r, cnt);
            r = sorted_rad[i];
            cnt = 1;
        }
        encode.emplace_back(r, cnt);
    }
    ll ans = 0, sum = 0;
    for (auto [r, cnt] : encode) {
        ans += sum * cnt;
        sum += cnt;
    }
    output(ans);
}
