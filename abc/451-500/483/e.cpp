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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    unordered_map<string, int> mp0, mp2_sum;
    map<string, unordered_map<int, int>> mp1, mp2;
    ll ans = 0;
    REP(i, n) {
        // 距離0
        ans += mp0[s[i]];
        ++mp0[s[i]];
        // 距離1
        REP(j, m) {
            string t = s[i];
            t[j] = '?';
            ll tmp = 0;
            int a = s[i][j] - 'a';
            for (auto p : mp1[t]) {
                if (p.first == a) continue;
                ans += p.second;
            }
            ++mp1[t][s[i][j] - 'a'];
        }
        // 距離2
        REP(j, m) {
            REP(k, j) {
                string t = s[i];
                t[j] = '?';
                t[k] = '?';
                ll tmp = 0;
                int a = s[i][j] - 'a';
                int b = s[i][k] - 'a';
                for (auto p : mp2[t]) {
                    int x = p.first / 26;
                    int y = p.first % 26;
                    if (a != x && b != y) {
                        tmp += p.second;
                    }
                }
                ans += tmp;
                ++mp2[t][(s[i][j] - 'a') * 26 + (s[i][k] - 'a')];
                ++mp2_sum[t];
            }
        }
    }
    output(ans);
}
