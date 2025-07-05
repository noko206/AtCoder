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
vector<int> solve(int n, vector<int> p) {
    vector<vector<int>> used(n + 1);
    int m = pow(2, n);
    REP(i, n + 1) {
        used[i].resize(m, 0);
        m /= 2;
    }
    m = pow(2, n);
    vector<int> pos(m);
    REP(i, m) pos[p[i] - 1] = i;
    auto dfs = [&](auto &dfs, int idx, int l, int r, int depth,
                   bool rev = false) -> void {
        if (r - l == 1) return;
        if (used[depth][l / (r - l)] != 0) {
            int mid = (l + r) / 2;
            if (used[depth][l / (r - l)] == -1) {
                rev = !rev;
            }
            if (l <= idx && idx < mid) {
                dfs(dfs, idx, l, mid, depth - 1, rev);
            } else {
                dfs(dfs, idx, mid, r, depth - 1, rev);
            }
            return;
        }
        if (rev) {
            int mid = (l + r) / 2;
            if (mid <= idx && idx < r) {
                dfs(dfs, idx, mid, r, depth - 1, rev);
                used[depth][l / (r - l)] = 1;
            } else {
                // 反転
                dfs(dfs, idx, l, mid, depth - 1, !rev);
                used[depth][l / (r - l)] = -1;
            }
        } else {
            int mid = (l + r) / 2;
            if (mid <= idx && idx < r) {
                // 反転
                dfs(dfs, idx, mid, r, depth - 1, !rev);
                used[depth][l / (r - l)] = -1;
            } else {
                dfs(dfs, idx, l, mid, depth - 1, rev);
                used[depth][l / (r - l)] = 1;
            }
        }
    };
    REP(i, m) dfs(dfs, pos[i], 0, m, n);
    int len = 1;
    REP(i, n + 1) {
        REP(j, used[i].size()) {
            if (used[i][j] == -1) {
                int l = j * len;
                int r = (j + 1) * len;
                reverse(p.begin() + l, p.begin() + r);
            }
        }
        len *= 2;
    }
    return p;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> ans(t);
    REP(i, t) {
        int n;
        cin >> n;
        int m = pow(2, n);
        vector<int> p(m);
        REP(j, m) cin >> p[j];
        ans[i] = solve(n, p);
    }
    REP(i, t) output(ans[i]);
}
