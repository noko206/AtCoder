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
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    REP(i, n - 1) {
        int p;
        cin >> p;
        --p;
        to[p].push_back(i + 1);
    }
    vector<int> cnt(n, -1);
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        chmax(cnt[x], y);
    }
    vector<bool> visited(n, false);
    auto dfs = [&](auto &dfs, int v, int tmp) -> void {
        if (visited[v]) return;
        visited[v] = true;
        chmax(tmp, cnt[v]);
        if (tmp == -1) return;
        cnt[v] = tmp;
        for (int u : to[v]) {
            dfs(dfs, u, tmp - 1);
        }
    };
    REP(i, n) {
        if (!visited[i]) {
            dfs(dfs, i, cnt[i]);
        }
    }
    int ans = 0;
    REP(i, n) {
        if (cnt[i] != -1) ++ans;
    }
    output(ans);
}
