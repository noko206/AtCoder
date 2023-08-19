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
    int v_size = 1 + n + 2 * m + n + 1;
    vector<vector<pair<int, int>>> to(v_size);
    REP(i, n) to[0].emplace_back(i + 1, 0);
    REP(i, n) to[1 + n + 2 * m + i].emplace_back(v_size - 1, 0);
    vector<tuple<int, int, int>> list;
    vector<int> a(m), s(m), t(m), b(m);
    REP(i, m) {
        cin >> a[i] >> s[i] >> b[i] >> t[i];
        --a[i], --b[i];
        t[i] += k;
        list.emplace_back(s[i], 1, i);
        list.emplace_back(t[i], 0, i);
    }
    sort(ALL(list));
    int id = 1 + n;
    map<pair<int, int>, int> mp;
    for (auto [v, flg, idx] : list) mp[{idx, flg}] = id++;
    for (auto [v, flg, idx] : list) {
        if (flg == 0) continue;
        to[mp[{idx, 1}]].emplace_back(mp[{idx, 0}], 1);
    }
    vector<vector<int>> same_v(n);
    for (auto [v, flg, idx] : list) {
        if (flg == 1) {
            same_v[a[idx]].push_back(mp[{idx, flg}]);
        } else {
            same_v[b[idx]].push_back(mp[{idx, flg}]);
        }
    }
    REP(i, n) {
        if (same_v[i].size() == 0) continue;
        sort(ALL(same_v[i]));
        to[1 + i].emplace_back(same_v[i][0], 0);
        REP(j, same_v[i].size() - 1) {
            to[same_v[i][j]].emplace_back(same_v[i][j + 1], 0);
        }
        to[same_v[i][same_v[i].size() - 1]].emplace_back(1 + n + 2 * m + i, 0);
    }
    vector<int> dp(v_size, -INF32);
    dp[0] = 0;
    REP(v, v_size) {
        if (dp[v] == -INF32) continue;
        for (auto [u, c] : to[v]) {
            chmax(dp[u], dp[v] + c);
        }
    }
    output(dp[v_size - 1]);
    // REP(v, v_size) {
    //     cout << v << ": ";
    //     for (auto [u, _] : to[v]) {
    //         cout << u << ' ';
    //     }
    //     cout << endl;
    // }
}
