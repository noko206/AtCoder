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
    vector<vector<int>> to(n);
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    string s;
    cin >> s;
    queue<tuple<int, int, int>> q;  // 今、出発点、コスト
    vector<pair<int, int>> dist1(n, {0, INF32}), dist2(n, {0, INF32});
    REP(v, n) {
        if (s[v] == 'D') continue;
        q.push({v, v, 0});
        dist1[v] = {v, 0};
    }
    while (!q.empty()) {
        auto [v, r, d] = q.front();
        q.pop();
        for (int u : to[v]) {
            if (dist1[u].first == r) {
                if (chmin(dist1[u].second, d + 1)) {
                    q.push({u, r, d + 1});
                }
            } else if (dist2[u].first == r) {
                if (chmin(dist2[u].second, d + 1)) {
                    q.push({u, r, d + 1});
                    if (dist1[u].second > dist2[u].second) {
                        swap(dist1[u], dist2[u]);
                    }
                }
            } else {
                if (dist1[u].second > d + 1) {
                    swap(dist1[u], dist2[u]);
                    dist1[u] = {r, d + 1};
                    q.push({u, r, d + 1});
                } else if (dist2[u].second > d + 1) {
                    dist2[u] = {r, d + 1};
                    q.push({u, r, d + 1});
                }
            }
        }
    }
    vector<int> ans;
    REP(v, n) {
        if (s[v] == 'S') continue;
        ans.push_back(dist1[v].second + dist2[v].second);
    }
    REP(i, ans.size()) output(ans[i]);
}
