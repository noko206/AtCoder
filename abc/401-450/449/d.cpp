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
ll f(int w, int h) {
    if (w <= 0 || h <= 0) return 0;
    ll ans = 0;
    REP(i, 1, h + 1) {
        if (i % 2 == 1) {
            // 白スタート
            if (w - i + 1 >= 0) {
                ans += (w - i + 1) / 2;
            }
        } else {
            // 黒スタート
            ans += min(i, w);
            if (w - i >= 0) {
                ans += (w - i) / 2;
            }
        }
    }
    return ans;
}

ll f(int l, int r, int d, int u) {
    assert(l >= 1 && d >= 1 && l <= r && d <= u);
    return f(r, u) - f(l - 1, u) - f(r, d - 1) + f(l - 1, d - 1);
}

ll solve(int l, int r, int d, int u) {
    ll ans = 0;
    // 第1象限
    if (r >= 1 && u >= 1) {
        ans += f(max(l, 1), r, max(d, 1), u);
    }
    // 第2象限
    if (l <= -1 && u >= 1) {
        ans += f(-min(r, -1), -l, max(d, 1), u);
    }
    // 第3象限
    if (l <= -1 && d <= -1) {
        ans += f(-min(r, -1), -l, -min(u, -1), -d);
    }
    // 第4象限
    if (r >= 1 && d <= -1) {
        ans += f(max(l, 1), r, -min(u, -1), -d);
    }
    // x軸上
    if (d <= 0 && u >= 0) {
        if (r > 0) {
            ans += (r / 2) - (max(l - 1, 1) / 2);
        }
        if (l < 0) {
            ans += (-l / 2) - (-min(r + 1, -1) / 2);
        }
    }
    // y軸上
    if (l <= 0 && r >= 0) {
        if (u > 0) {
            ans += (u / 2) - (max(d - 1, 1) / 2);
        }
        if (d < 0) {
            ans += (-d / 2) - (-min(u + 1, -1) / 2);
        }
    }
    // 原点
    if (l <= 0 && 0 <= r && d <= 0 && 0 <= u) {
        ++ans;
    }
    return ans;
}

ll naive(int l, int r, int d, int u) {
    ll ans = 0;
    REP(x, l, r + 1) {
        REP(y, d, u + 1) {
            if (max(abs(x), abs(y)) % 2 == 0) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    output(solve(l, r, d, u));

    // int range = 5;
    // REP(l, -range, range + 1) {
    //     REP(r, l, range) {
    //         REP(d, -range, range + 1) {
    //             REP(u, d, range + 1) {
    //                 int naive_ans = naive(l, r, d, u);
    //                 int solve_ans = solve(l, r, d, u);
    //                 if (naive_ans != solve_ans) {
    //                     output(l, r, d, u);
    //                     output(naive_ans, solve_ans);
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    // }
}
