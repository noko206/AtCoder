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
using P = pair<int, ll>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> to(n);
    dsu uf(n);
    REP(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x, --y;
        to[x].emplace_back(y, z);
        to[y].emplace_back(x, z);
        if (!uf.same(x, y)) {
            uf.merge(x, y);
        }
    }
    vector<int> value(n, -1);
    auto groups = uf.groups();
    vector<ll> ans(n, 0);
    REP(bit, 32) {
        auto dfs = [&](auto &dfs, int x, bool is_one = false) -> void {
            value[x] = is_one ? 1 : 0;
            for (auto [y, z] : to[x]) {
                if (value[y] != -1) continue;
                if (z & (1LL << bit)) {
                    // 異なる
                    dfs(dfs, y, !is_one);
                } else {
                    // 同じ
                    dfs(dfs, y, is_one);
                }
            }
        };
        REP(i, n) value[i] = -1;
        for (auto &g : groups) {
            int root = g.front();
            assert(value[root] == -1);
            dfs(dfs, root);
        }
        bool is_ok = true;
        for (auto &g : groups) {
            for (auto x : g) {
                for (auto [y, z] : to[x]) {
                    if (z & (1LL << bit)) {
                        if (value[x] == value[y]) {
                            is_ok = false;
                            break;
                        }
                    } else {
                        if (value[x] != value[y]) {
                            is_ok = false;
                            break;
                        }
                    }
                }
            }
        }
        if (!is_ok) {
            output(-1);
            return 0;
        }
        for (auto &g : groups) {
            int cnt = 0;
            for (auto x : g) {
                if (value[x] == 1) cnt++;
            }
            if (cnt <= (int)g.size() - cnt) {
                // 1の方が少ない
                for (auto x : g) {
                    if (value[x] == 1) {
                        ans[x] |= 1LL << bit;
                    }
                }
            } else {
                // 0の方が少ない
                for (auto x : g) {
                    if (value[x] == 0) {
                        ans[x] |= 1LL << bit;
                    }
                }
            }
        }
    }
    output(ans);
}
