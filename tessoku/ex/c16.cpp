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
    vector<vector<tuple<int, int, ll>>> to(1 + n + 2 * m + n + 1);
    REP(i, n) {
        to[0].emplace_back(i + 1, 0, 0);
        to[1 + n + 2 * m + i].emplace_back(1 + n + 2 * m + n, 0, INF64);
    }
    vector<vector<tuple<int, int, int, int>>> vertex(n);
    REP(i, m) {
        vertex[a[i]].emplace_back(s[i], 1, 1 + n + 2 * i, i);
        vertex[b[i]].emplace_back(t[i], 0, 1 + n + 2 * i + 1, i);
        to[1 + n + 2 * i].emplace_back(1 + n + 2 * i + 1, 1, t[i]);
    }
    REP(i, n) {
        int sz = vertex[i].size();
        if (sz == 0) continue;
        sort(ALL(vertex[i]));
        auto [_1, _2, sv, sidx] = vertex[i][0];
        to[1 + i].emplace_back(sv, 0, t[sidx]);
        REP(j, sz - 1) {
            auto [_3, _4, v, _5] = vertex[i][j];
            auto [_6, _7, u, uidx] = vertex[i][j + 1];
            to[v].emplace_back(u, 0, t[uidx]);
        }
        auto [_8, _9, gv, _10] = vertex[i][sz - 1];
        to[gv].emplace_back(1 + n + 2 * m + i, 0, INF64);
    }
    vector<int> dp(1 + n + 2 * m + n + 1, 0);
    vector<bool> is_added(1 + n + 2 * m + n + 1, false);
    is_added[0] = true;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [_, v] = q.top();
        q.pop();
        for (auto [u, w, c] : to[v]) {
            chmax(dp[u], dp[v] + w);
            if (!is_added[u]) {
                q.push({c, u});
                is_added[u] = true;
            }
        }
    }
    output(dp[1 + n + 2 * m + n]);
    // output("---");
    // output(dp[0]);
    // REP(i, n) cout << dp[1 + i] << ' ';
    // cout << endl;
    // REP(i, 2 * m) cout << dp[1 + n + i] << ' ';
    // cout << endl;
    // REP(i, n) cout << dp[1 + n + 2 * m + i] << ' ';
    // cout << endl;
    // output(dp[1 + n + 2 * m + n]);
}
