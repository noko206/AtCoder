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
struct S {
    int cntL;
    int cntR;
    int cntMax;
    int val;
    S(int val) : val(val) {
        if (val == 0) {
            cntL = 0;
            cntR = 0;
            cntMax = 0;
        } else {
            cntL = 1;
            cntR = 1;
            cntMax = 1;
        }
    }
};

S op(S a, S b) {
    int cntL = a.cntL;
    if (a.cntL == a.cntMax) {
        cntL += b.cntL;
    }
    int cntR = b.cntR;
    if (b.cntR == b.cntMax) {
        cntR += a.cntR;
    }
    int cntMax = max({a.cntMax, b.cntMax, a.cntR + b.cntL});
    int val = -1;
    return {cntL, cntR, cntMax, val};
}

S e() { return S(0); }

using F = int;

S mapping(F f, S x) {
    if (f == x.val) continue;
    if (f ==) }

F composition(F f, F g) {}

F id() { return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree<S, op, e> seg(n);
    vector<int> ans;
    REP(i, q) {
        int c, l, r;
        cin >> c >> l >> r;
        --l;
        if (c == 1) {
        } else {
        }
    }
}
