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
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if (sy % 2 == 0 && abs(sx) % 2 == 1) {
        sx += -1;
    }
    if (sy % 2 == 1 && abs(sx) % 2 == 0) {
        sx += -1;
    }
    if (ty % 2 == 0 && abs(tx) % 2 == 1) {
        tx += -1;
    }
    if (ty % 2 == 1 && abs(tx) % 2 == 0) {
        tx += -1;
    }
    ll new_sx, new_sy, new_tx, new_ty;
    new_sx = 0;
    new_sy = 0;
    ll dx = new_sx - sx;
    ll dy = new_sy - sy;
    new_tx = tx + dx;
    new_ty = ty + dy;
    if (new_ty < 0) new_ty *= -1;
    if (new_tx < 0) new_tx = new_tx * -1 + 1;
    // 例外処理
    if (new_tx == 0) {
        output(new_ty - new_sy);
        return 0;
    }
    if (new_ty % 2 == 0 && new_tx % 2 == 1) {
        new_tx += -1;
    }
    if (new_ty % 2 == 1 && new_tx % 2 == 0) {
        new_tx += -1;
    }
    // 確認
    // output(new_sx, new_sy);
    // output(new_tx, new_ty);
    ll new_dy = new_ty - new_sy;
    ll new_dx = new_tx - new_sx;
    ll mn = min(new_dy, new_dx);
    ll ans = mn;
    new_sx += mn;
    new_sy += mn;
    if (new_sx == new_tx) {
        ans += new_ty - new_sy;
    } else {
        ans += (new_tx - new_sx) / 2;
    }
    output(ans);
}
