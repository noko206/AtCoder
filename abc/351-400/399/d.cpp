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
void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    REP(i, m) cin >> a[i], --a[i];
    vector<vector<pair<int, int>>> p(n);
    REP(i, m) {
        int left = -1, right = -1;
        if (i - 1 >= 0) left = a[i - 1];
        if (i + 1 < m) right = a[i + 1];
        p[a[i]].emplace_back(left, right);
    }
    vector<bool> ng(n, false);
    REP(i, m - 1) {
        if (a[i] == a[i + 1]) {
            ng[a[i]] = true;
        }
    }
    map<pair<int, int>, bool> mp;
    REP(i, m) {
        if (ng[a[i]]) continue;
        if (i - 1 >= 0) {
            int left = a[i - 1];
            if (!ng[left]) {
                int cnt = 0;
                REP(j, 2) {
                    auto [l, r] = p[left][j];
                    if (a[i] == l || a[i] == r) ++cnt;
                }
                REP(j, 2) {
                    auto [l, r] = p[a[i]][j];
                    if (left == l || left == r) ++cnt;
                }
                if (cnt == 4) {
                    mp[{left, a[i]}] = true;
                    mp[{a[i], left}] = true;
                }
            }
        }
        if (i + 1 < m) {
            int right = a[i + 1];
            if (!ng[right]) {
                int cnt = 0;
                REP(j, 2) {
                    auto [l, r] = p[right][j];
                    if (a[i] == l || a[i] == r) ++cnt;
                }
                REP(j, 2) {
                    auto [l, r] = p[a[i]][j];
                    if (right == l || right == r) ++cnt;
                }
                if (cnt == 4) {
                    mp[{right, a[i]}] = true;
                    mp[{a[i], right}] = true;
                }
            }
        }
    }
    int tmp = mp.size();
    assert(tmp % 2 == 0);
    output(tmp / 2);
    // for (auto [p, _] : mp) {
    //     auto [l, r] = p;
    //     output(l + 1, r + 1);
    // }
}

int main() {
    int t;
    cin >> t;
    REP(i, t) solve();
}
