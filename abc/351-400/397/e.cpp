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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> to(n * k);
    REP(i, n * k - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    if (k == 1) {
        output("Yes");
        return 0;
    }
    queue<int> q;
    vector<int> parent(n * k, -1);
    auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
        parent[v] = p;
        if (v != 0 && to[v].size() == 1) {
            q.push(v);
            return;
        }
        for (int u : to[v]) {
            if (u == p) continue;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs);
    vector<int> size(n * k, -1);
    vector<bool> pending(n, false);
    bool is_ok = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (size[v] == -1) {
            size[v] = 1;
        }
        while (true) {
            output(v + 1);
            int p = parent[v];
            if (p == -1) {
                break;
            }
            if (size[v] == k) {
                break;
            }
            if (pending[p]) {
                if (size[p] + size[v] == k) {
                    pending[p] = false;
                    if (p != 0) {
                        q.push(parent[p]);
                    }
                    break;
                } else {
                    is_ok = false;
                    break;
                }
            } else {
                if (size[p] == -1) {
                    v = p;
                    size[p] = size[v] + 1;
                } else {
                    is_ok = false;
                    break;
                }
            }
        }
    }
    REP(i, n * k) {
        if (size[i] == -1) {
            is_ok = false;
        }
    }
    YesNo(is_ok);
}
