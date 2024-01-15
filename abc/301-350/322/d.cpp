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
    vector p(3, vector<string>(4));
    REP(i, 3) REP(j, 4) cin >> p[i][j];
    vector<int> cnt_sharp(3);
    REP(i, 3) {
        int sum = 0;
        REP(j, 4) {
            REP(k, 4) {
                if (p[i][j][k] == '#') ++sum;
            }
        }
        cnt_sharp[i] = sum;
    }
    auto rotate = [](const vector<string> s, int r) -> vector<string> {
        if (r == 0) return s;
        vector<string> ans(4, "....");
        if (r == 1) {
            REP(i, 4) {
                REP(j, 4) { ans[i][j] = s[j][3 - i]; }
            }
        } else if (r == 2) {
            REP(i, 4) {
                REP(j, 4) { ans[i][j] = s[3 - i][3 - j]; }
            }
        } else if (r == 3) {
            REP(i, 4) {
                REP(j, 4) { ans[i][j] = s[3 - j][i]; }
            }
        }
        return ans;
    };
    // REP(r, 4) {
    //     output("????");
    //     auto s = rotate(p[0], r);
    //     REP(i, 4) { cout << s[i] << endl; }
    // }
    // return 0;
    auto f = [&](auto &tot, int id, int r, int x, int y, int k) -> bool {
        --id;
        int cnt = 0;
        auto s = rotate(p[id], r);
        REP(i, 4) {
            REP(j, 4) {
                if (s[i][j] == '.') continue;
                int ny = y + i - 3;
                int nx = x + j - 3;
                if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
                tot[ny][nx] += k;
                ++cnt;
            }
        }
        bool is_ok = true;
        if (cnt != cnt_sharp[id]) is_ok = false;
        REP(i, 4) REP(j, 4) if (tot[i][j] >= 2) is_ok = false;
        return is_ok;
    };
    vector tot(4, vector<int>(4, 0));
    REP(r1, 4) {
        REP(x1, 7) {
            REP(y1, 7) {
                if (!f(tot, 1, r1, x1, y1, 1)) {
                    f(tot, 1, r1, x1, y1, -1);
                    continue;
                }
                REP(r2, 4) {
                    REP(x2, 7) {
                        REP(y2, 7) {
                            if (!f(tot, 2, r2, x2, y2, 1)) {
                                f(tot, 2, r2, x2, y2, -1);
                                continue;
                            }
                            REP(r3, 4) {
                                REP(x3, 7) {
                                    REP(y3, 7) {
                                        if (!f(tot, 3, r3, x3, y3, 1)) {
                                            f(tot, 3, r3, x3, y3, -1);
                                            continue;
                                        }
                                        bool is_ok = true;
                                        REP(i, 4) {
                                            REP(j, 4) {
                                                if (tot[i][j] != 1) {
                                                    is_ok = false;
                                                }
                                            }
                                        }
                                        if (is_ok) {
                                            output("Yes");
                                            return 0;
                                        }
                                        f(tot, 3, r3, x3, y3, -1);
                                    }
                                }
                            }
                            f(tot, 2, r2, x2, y2, -1);
                        }
                    }
                }
                f(tot, 1, r1, x1, y1, -1);
            }
        }
    }
    output("No");
}
