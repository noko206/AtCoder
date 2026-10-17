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
using S = pair<ll, ll>;
using F = pair<ll, ll>;

S op(S a, S b) {
    auto [ao, ax] = a;
    auto [bo, bx] = b;
    if (ao * (bo + bx) >= bo * (ao + ax)) {
        return a;
    } else {
        return b;
    }
}
S e() { return {0, 2000000}; }
S mapping(F f, S x) { return {f.first + x.first, f.second + x.second}; }
F composition(F f, F g) { return {f.first + g.first, f.second + g.second}; }
F id() { return {0, 0}; }

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
        output(1);
        return 0;
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    int cntO = 0, cntX = 0;
    REP(i, n) {
        if (s[i] == 'o') {
            ++cntO;
        } else {
            ++cntX;
        }
        seg.set(i, {cntO, cntX});
    }
    double ans = 0.0;
    int cnt = 0, l = 0;
    REP(i, n) {
        if (s[i] == 'x') {
            seg.apply(i, n, {0, -1});
            continue;
        }
        chmax(l, i);
        while (l < n) {
            if (s[l] == 'o') {
                ++cnt;
            }
            if (cnt == k) break;
            ++l;
        }
        if (cnt != k) break;
        auto [x, y] = seg.prod(l, n);
        chmax(ans, x / (double)(x + y));
        // output(x, y, i, l);
        --cnt;
        seg.apply(i, n, {-1, 0});
        ++l;
    }
    output(ans);
}
