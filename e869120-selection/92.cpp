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
    vector<int> ans;
    while (true) {
        int h;
        cin >> h;
        if (h == 0) break;
        vector a(h, vector<int>(6, 0));  // 6番目に番兵を置く
        REP(i, h) REP(j, 5) cin >> a[i][j];
        int score = 0;
        while (true) {
            int sum = 0;
            // 消す処理
            REP(i, h) {
                int now = -1;
                int cnt = 0;
                REP(j, 6) {
                    if (now == a[i][j]) {
                        ++cnt;
                    } else {
                        if (cnt >= 3) {
                            sum += now * cnt;
                            REP(k, cnt) { a[i][j - k - 1] = 0; }
                        }
                        now = a[i][j];
                        cnt = 1;
                    }
                }
            }
            if (sum == 0) break;
            // 落とす処理
            RREP(i, h - 2) {
                REP(j, 5) {
                    int k = 1;
                    int now = a[i][j];
                    while (i + k < h && a[i + k][j] == 0) {
                        a[i + k - 1][j] = 0;
                        a[i + k][j] = now;
                        ++k;
                    }
                }
            }
            score += sum;
        }
        ans.push_back(score);
    }
    for (int v : ans) {
        output(v);
    }
}
