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
int op1(int a, int b) { return min(a, b); }

int e1() { return INF32; }

int op2(int a, int b) { return max(a, b); }

int e2() { return -INF32; }

int main() {
    int n;
    cin >> n;
    vector<int> l(n), u(n);
    REP(i, n) cin >> l[i] >> u[i];
    segtree<int, op1, e1> maxL(n);
    segtree<int, op2, e2> minU(n);
    REP(i, n) {
        maxL.set(i, l[i]);
        minU.set(i, u[i]);
    }
    vector<ll> totL(n, 0), totU(n, 0);
    int now = l[i];
    REP(i, n - 1) {
        if (l[i + 1] <= now && now <= u[i + 1]) {
            totL[i + 1] = totL[i] + 1;
        } else {
            if (abs(l[i] - l[i + 1]) < abs(l[i] - u[i + 1])) {
                totL[i + 1] = totL[i] + abs(l[i] - l[i + 1]) + 1;
                now = l[i + 1];
            } else {
                totL[i + 1] = totL[i] + abs(l[i] - u[i + 1]) + 1;
                now = u[i + 1];
            }
        }
    }
    now = u[i];
    REP(i, n - 1) {
        if (l[i + 1] <= now && now <= u[i + 1]) {
            totU[i + 1] = totU[i] + 1;
        } else {
            if (abs(l[i] - l[i + 1]) < abs(l[i] - u[i + 1])) {
                totU[i + 1] = totU[i] + abs(l[i] - l[i + 1]) + 1;
                now = l[i + 1];
            } else {
                totU[i + 1] = totU[i] + abs(l[i] - u[i + 1]) + 1;
                now = u[i + 1];
            }
        }
    }
    int q;
    cin >> q;
    REP(i, q) {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        --sx, --tx;
        // 左から右へ向かう
        if (sx > tx) {
            swap(sx, tx);
            swap(sy, ty);
        }
        // 左から直線でどこまで進めるか
        int okL, okR;
        {
            int ok = sx;
            int ng = n;
            while (ng - ok != 1) {
                int mid = (ok + ng) / 2;
                int tmpL = maxL.prod(sx, mid + 1);
                int tmpU = minU.prod(sx, mid + 1);
                if (tmpL <= sy && sy <= tmpU) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            okL = ok;
        }
        // 右から直線でどこまで進めるか
        {
            int ok = tx;
            int ng = -1;
            while (ok - ng != 1) {
                int mid = (ok + ng) / 2;
                int tmpL = maxL.prod(mid, tx + 1);
                int tmpU = minU.prod(mid, tx + 1);
                if (tmpL <= ty && ty <= tmpU) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            okR = ok;
        }
        if (okR <= okL) {
            // 直線で合流できる場合はy座標の差分がほぼ答え
            ll ans = 0;
            ans = tx - sx + abs(sy - ty);
            output(ans);
        } else {
            // そうでない場合は、上下に張り付きながら移動
            ll ans = 0;
            ans += okL - sx;
            ans += tx - okR;
            if (abs(sy - l[okL + 1]) < abs(sy - u[okL + 1])) {
                ans += abs(sy - l[okL + 1]) + 1;
                if (abs(ty - l[okR]) < abs(ty - u[okR])) {
                    ans += abs(ty - l[okR]);
                    ans += totL[okR + 1] - totL[okL];
                } else {
                }
            }
        }
    }
}
