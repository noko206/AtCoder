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
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    bool is_ok = false;
    vector t(h, vector<bool>(w, false));
    auto dfs = [&](auto &dfs, const vector<int> &p, int num = 0) -> void {
        if (is_ok) return;
        if (num == p.size()) {
            bool ok = true;
            REP(i, h) {
                REP(j, w) {
                    if (!t[i][j]) {
                        ok = false;
                    }
                }
            }
            if (ok) is_ok = true;
            return;
        }
        int _a = a[p[num]], _b = b[p[num]];
        bool is_break = false;
        REP(_, 2) {
            REP(i, h) {
                if (i + _a - 1 >= h) break;
                REP(j, w) {
                    if (j + _b - 1 >= w) break;
                    bool ok = true;
                    REP(di, _a) {
                        REP(dj, _b) {
                            if (t[i + di][j + dj]) {
                                ok = false;
                            }
                        }
                    }
                    if (ok) {
                        // 塗る
                        REP(di, _a) {
                            REP(dj, _b) { t[i + di][j + dj] = true; }
                        }
                        dfs(dfs, p, num + 1);
                        // 戻す
                        REP(di, _a) {
                            REP(dj, _b) { t[i + di][j + dj] = false; }
                        }
                        is_break = true;
                        break;
                    }
                }
                if (is_break) break;
            }
            is_break = false;
            swap(_a, _b);
        }
    };
    REP(bit, 1, 1 << n) {
        if (is_ok) break;
        vector<int> p;
        REP(i, n) {
            if (bit & (1 << i)) {
                p.push_back(i);
            }
        }
        do {
            dfs(dfs, p);
        } while (next_permutation(ALL(p)));
    }
    YesNo(is_ok);
}
