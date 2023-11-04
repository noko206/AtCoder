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
    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i], --a[i];
    REP(i, m) cin >> b[i], --b[i];
    vector<vector<int>> to(n);
    map<pair<int, int>, bool> mp;
    REP(i, m) {
        if (a[i] == b[i]) {
            output("No");
            return 0;
        }
        if (mp.find({a[i], b[i]}) != mp.end()) continue;
        if (mp.find({b[i], a[i]}) != mp.end()) continue;
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);
        mp[{a[i], b[i]}] = true;
    }
    vector<int> bit(n, -1);
    bool is_ok = true;
    auto dfs = [&](auto &dfs, int v, int b = 0) -> void {
        bit[v] = b;
        for (int u : to[v]) {
            if (bit[u] == b) {
                is_ok = false;
                continue;
            }
            if (bit[u] == -1) {
                dfs(dfs, u, (b + 1) % 2);
            }
        }
    };
    REP(i, n) {
        if (bit[i] != -1) continue;
        dfs(dfs, i);
    }
    YesNo(is_ok);
}
