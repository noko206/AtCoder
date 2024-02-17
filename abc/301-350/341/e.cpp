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
using S = int;
using F = int;

S op(S a, S b) { return std::max(a, b); }
S e() { return 0; }
S mapping(F f, S x) { return (f + x) % 2; }
F composition(F f, F g) { return (f + g) % 2; }
F id() { return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    REP(i, n) { seg.set(i, s[i] - '0'); }
    fenwick_tree<int> ft(n);
    REP(i, n - 1) {
        if (s[i] != s[i + 1]) {
            ft.add(i, 1);
        }
    }
    ft.add(n - 1, 1);
    vector<bool> ans;
    REP(i, q) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 1) {
            seg.apply(l, r, 1);
            if (l - 1 >= 0) {
                if (seg.get(l - 1) == seg.get(l)) {
                    ft.add(l - 1, -1);
                } else {
                    ft.add(l - 1, 1);
                }
            }
            if (r <= n - 1) {
                if (seg.get(r - 1) == seg.get(r)) {
                    ft.add(r - 1, -1);
                } else {
                    ft.add(r - 1, 1);
                }
            }
        } else {
            ans.push_back(ft.sum(l, r - 1) == r - l - 1);
        }
    }
    REP(i, ans.size()) YesNo(ans[i]);
}
