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
using S = pair<int, int>;  // 番号, 票数

S op(S a, S b) {
    if (a.second > b.second) {
        return a;
    } else if (a.second < b.second) {
        return b;
    } else {
        return a.first < b.first ? a : b;
    }
}

S e() { return {-1, -1}; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i], --a[i], --b[i];
    vector<vector<int>> to(n);
    REP(i, m) to[a[i]].push_back(b[i]);
    segtree<S, op, e> seg(n);
    REP(i, n) seg.set(i, {i, 0});
    REP(i, m) seg.set(a[i], {a[i], seg.get(a[i]).second + 1});
    vector<int> ans(n);
    REP(x, n) {
        for (int y : to[x]) {
            seg.set(x, {x, seg.get(x).second - 1});
            seg.set(y, {y, seg.get(y).second + 1});
        }
        ans[x] = seg.all_prod().first + 1;
        for (int y : to[x]) {
            seg.set(x, {x, seg.get(x).second + 1});
            seg.set(y, {y, seg.get(y).second - 1});
        }
    }
    REP(i, n) output(ans[i]);
}
