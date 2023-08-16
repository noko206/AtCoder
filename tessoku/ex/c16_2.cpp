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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), s(m), b(m), t(m);
    REP(i, m) {
        cin >> a[i] >> s[i] >> b[i] >> t[i];
        t[i] += k;
        --a[i];
        --b[i];
    }
    int sz = 1 + n + 2 * m + n + 1;
    vector<vector<int>> to(sz);
    REP(i, n) {
        to[0].push_back(i + 1);
        to[1 + n + 2 * m + i].push_back(sz - 1);
    }
    vector<vector<tuple<ll, int, int>>> v(n);
    REP(i, m) {
        v[a[i]].emplace_back(s[i], 1, 1 + n + 2 * i);
        v[b[i]].emplace_back(t[i], 0, 1 + n + 2 * i + 1);
        to[1 + n + 2 * i].push_back(1 + n + 2 * i + 1);
    }
	vector<int> ch(sz);
	REP(i, sz) ch[i] = i;
	int now = 0;
    REP(i, n) {
        int num = v[i].size();
        if (num == 0) continue;
        sort(ALL(v[i]));
        auto [st, sf, si] = v[i][0];
        to[1 + i].push_back(si);
        REP(j, num - 1) {
            auto [vt, vf, vi] = v[i][j];
            auto [ut, uf, ui] = v[i][j + 1];
            to[vi].push_back(ui);
        }
        auto [gt, gf, gi] = v[i][num - 1];
        to[gi].push_back(1 + n + 2 * m + i);
    }
    vector<int> dp(sz, -INF32);
    dp[0] = 0;
    for (auto x : g.scc()) {
        for (int y : x) {
            if (1 + n <= y && y < 1 + n + 2 * m) {
                for (int z : to[y]) {
                    if (z >= 1 + n + 2 * m) {
                        chmax(dp[z], dp[y]);
                        continue;
                    }
                    int tmp_y = y - (1 + n);
                    int tmp_z = z - (1 + n);
                    if (tmp_y % 2 == 0 && tmp_z % 2 == 1) {
                        chmax(dp[z], dp[y] + 1);
                    } else {
                        chmax(dp[z], dp[y]);
                    }
                }
            } else {
                for (int z : to[y]) {
                    chmax(dp[z], dp[y]);
                }
            }
        }
    }
    output(dp[sz - 1]);
}
