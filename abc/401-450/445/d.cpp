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
using S = pair<int, int>;

S op(S a, S b) { return a.second > b.second ? a : b; }

S e() { return {-1, 0}; }

int main() {
    int H, W, n;
    cin >> H >> W >> n;
    vector<int> h(n), w(n);
    REP(i, n) cin >> h[i] >> w[i];
    segtree<pair<int, int>, op, e> segH(n), segW(n);
    REP(i, n) {
        segH.set(i, {i, h[i]});
        segW.set(i, {i, w[i]});
    }
    vector<pair<int, int>> ans(n);
    REP(_, n) {
        S maxH = segH.all_prod();
        S maxW = segW.all_prod();
        if (maxH.second == H) {
            auto [i, len] = maxH;
            // output(i + 1);
            ans[i] = {1, W - w[i] + 1};
            segH.set(i, {-1, 0});
            segW.set(i, {-1, 0});
            W -= w[i];
        } else if (maxW.second == W) {
            auto [i, len] = maxW;
            // output(i + 1);
            ans[i] = {H - h[i] + 1, 1};
            segW.set(i, {-1, 0});
            segH.set(i, {-1, 0});
            H -= h[i];
        } else {
            assert(false);
        }
    }
    REP(i, n) output(ans[i].first, ans[i].second);
}
