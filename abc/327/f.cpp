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
using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    std::vector<S> v(200010);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    int n, d, w;
    cin >> n >> d >> w;
    vector<vector<int>> to(200010);
    REP(i, n) {
        int t, x;
        cin >> t >> x;
        to[x].push_back(t);
    }
    REP(i, 1, w) {
        for (int t : to[i]) {
            seg.apply(max(t - d + 1, 0), t + 1, 1);
        }
    }
    ll ans = 0;
    REP(i, w, 200005) {
        for (int t : to[i]) {
            seg.apply(max(t - d + 1, 0), t + 1, 1);
        }
        chmax(ans, seg.all_prod());
        for (int t : to[i - w + 1]) {
            seg.apply(max(t - d + 1, 0), t + 1, -1);
        }
    }
    output(ans);
}
