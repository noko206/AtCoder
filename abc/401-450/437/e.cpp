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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    vector<int> v_to_id(n + 1);
    vector<vector<int>> id_to_vs(n + 1);
    vector<map<int, int>> to(n + 1);
    id_to_vs[0].push_back(0);
    int id = 0;
    REP(i, n) {
        int id_v = v_to_id[x[i]];
        if (to[id_v].find(y[i]) == to[id_v].end()) {
            to[id_v][y[i]] = id + 1;
            ++id;
        }
        v_to_id[i + 1] = to[id_v][y[i]];
        id_to_vs[to[id_v][y[i]]].push_back(i + 1);
    }
    vector<int> ans;
    auto dfs = [&](auto& dfs, int id_v = 0) -> void {
        for (auto [_, id_u] : to[id_v]) {
            for (int u : id_to_vs[id_u]) {
                ans.push_back(u);
            }
            dfs(dfs, id_u);
        }
    };
    dfs(dfs);
    output(ans);
    // REP(i, n) output(id_to_vs[i]);
}
