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
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 0);
    vector<int> pre(n, INF32);
    pre[0] = 0;
    while (!pq.empty()) {
        auto [mn, v] = pq.top();
        pq.pop();
        if (pre[v] < mn) {
            continue;
        }
        for (int u : to[v]) {
            if (chmin(pre[u], max(pre[v], v))) {
                pq.emplace(pre[u], u);
            }
        }
    }
    fenwick_tree<int> ft(n);
    vector<int> ans(n);
    int pos = 0;
    REP(v, n) {
        for (int u : to[v]) {
            if (ft.sum(u, u + 1) == 0) {
                ft.add(u, 1);
            }
        }
        while (pos < n && pos <= v) {
            if (pre[pos] <= v) {
                ++pos;
            } else {
                break;
            }
        }
        if (v >= pos) {
            ans[v] = -1;
        } else {
            ans[v] = ft.sum(v + 1, n);
        }
    }
    REP(i, n) output(ans[i]);
}
