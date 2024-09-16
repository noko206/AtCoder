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
    int h, w, q;
    cin >> h >> w >> q;
    vector RtoC(h, dsu(w)), CtoR(w, dsu(h));
    vector is_wall(h, vector<bool>(w, true));
    vector minU(h, vector<int>(w));
    vector maxD(h, vector<int>(w));
    vector minL(h, vector<int>(w));
    vector maxR(h, vector<int>(w));
    REP(i, h) REP(j, w) {
        minU[i][j] = i;
        maxD[i][j] = i;
        minL[i][j] = j;
        maxR[i][j] = j;
    }
    auto f = [&](int r, int c) -> void {
        if (r < 0 || c < 0 || r >= h || c >= w) return;
        is_wall[r][c] = false;
        // 上
        int tmpU = r - 1;
        if (r - 1 >= 0 && !is_wall[r - 1][c]) {
            tmpU = minU[CtoR[c].leader(r - 1)][c];
        }
        // 下
        int tmpD = r + 1;
        if (r + 1 < h && !is_wall[r + 1][c]) {
            tmpD = maxD[CtoR[c].leader(r + 1)][c];
        }
        // 左
        int tmpL = c - 1;
        if (c - 1 >= 0 && !is_wall[r][c - 1]) {
            tmpL = minL[r][RtoC[r].leader(c - 1)];
        }
        // 右
        int tmpR = c + 1;
        if (c + 1 < w && !is_wall[r][c + 1]) {
            tmpR = maxR[r][RtoC[r].leader(c + 1)];
        }
        // 結合パート
        if (r - 1 >= 0 && !is_wall[r - 1][c] && !CtoR[c].same(r, r - 1)) {
            CtoR[c].merge(r, r - 1);
        }
        if (r + 1 < h && !is_wall[r + 1][c] && !CtoR[c].same(r, r + 1)) {
            CtoR[c].merge(r, r + 1);
        }
        if (c - 1 >= 0 && !is_wall[r][c - 1] && !RtoC[r].same(c, c - 1)) {
            RtoC[r].merge(c, c - 1);
        }
        if (c + 1 < w && !is_wall[r][c + 1] && !RtoC[r].same(c, c + 1)) {
            RtoC[r].merge(c, c + 1);
        }
        // 更新パート
        minU[CtoR[c].leader(r)][c] = tmpU;
        maxD[CtoR[c].leader(r)][c] = tmpD;
        minL[r][RtoC[r].leader(c)] = tmpL;
        maxR[r][RtoC[r].leader(c)] = tmpR;
    };
    REP(i, q) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (is_wall[r][c]) {
            f(r, c);
        } else {
            f(minU[CtoR[c].leader(r)][c], c);
            f(maxD[CtoR[c].leader(r)][c], c);
            f(r, minL[r][RtoC[r].leader(c)]);
            f(r, maxR[r][RtoC[r].leader(c)]);
        }
        // cout << i << "回目" << endl;
        // REP(i, h) {
        //     REP(j, w) { cout << (is_wall[i][j] ? "#" : "."); }
        //     cout << endl;
        // }
    }
    int ans = 0;
    REP(i, h) REP(j, w) {
        if (is_wall[i][j]) {
            ++ans;
        }
    }
    output(ans);
}
