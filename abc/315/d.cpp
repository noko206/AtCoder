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
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    REP(i, h) cin >> c[i];
    vector cntH(h, vector<int>(26, 0));
    vector cntW(w, vector<int>(26, 0));
    REP(i, h) {
        REP(j, w) {
            ++cntH[i][c[i][j] - 'a'];
            ++cntW[j][c[i][j] - 'a'];
        }
    }
    while (true) {
        vector<pair<int, int>> delH, delW;
        REP(i, h) {
            int cnt = 0;
            bool ok = false;
            REP(j, 26) {
                if (cntH[i][j] > 0) {
                    ++cnt;
                    if (cntH[i][j] >= 2) {
                        ok = true;
                    }
                }
            }
            if (cnt == 1 && ok) {
                REP(j, 26) {
                    if (cntH[i][j] > 0) {
                        delH.emplace_back(i, j);
                    }
                }
            }
        }
        REP(i, w) {
            int cnt = 0;
            bool ok = false;
            REP(j, 26) {
                if (cntW[i][j] > 0) {
                    ++cnt;
                    if (cntW[i][j] >= 2) {
                        ok = true;
                    }
                }
            }
            if (cnt == 1 && ok) {
                REP(j, 26) {
                    if (cntW[i][j] > 0) {
                        delW.emplace_back(i, j);
                    }
                }
            }
        }
        for (auto [i, j] : delH) {
            cntH[i][j] = 0;
            REP(k, w) {
                if (c[i][k] != '#') {
                    --cntW[k][j];
                    c[i][k] = '#';
                }
            }
        }
        for (auto [i, j] : delW) {
            cntW[i][j] = 0;
            REP(k, h) {
                if (c[k][i] != '#') {
                    --cntH[k][j];
                    c[k][i] = '#';
                }
            }
        }
        if (delH.size() == 0 && delW.size() == 0) {
            break;
        }
    }
    int ans = 0;
    REP(i, h) {
        REP(j, 26) { ans += cntH[i][j]; }
    }
    output(ans);
    // output("---");
    // REP(i, h) {
    //     int sum = 0;
    //     REP(j, 26) { sum += cntH[i][j]; }
    //     output(sum);
    // }
}
