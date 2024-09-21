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
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    vector<set<int>> st(n);
    REP(i, n) st[i].insert(i);
    vector<int> to(n);
    REP(i, n) to[i] = i;
    vector<int> ans;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            if (!uf.same(u, v)) {
                int ul = to[uf.leader(u)];
                int vl = to[uf.leader(v)];
                uf.merge(u, v);
                int ml = to[uf.leader(u)];
                if (st[ul].size() < st[vl].size()) {
                    to[ml] = vl;
                    for (auto v : st[ul]) {
                        st[vl].insert(v);
                    }
                } else {
                    to[ml] = ul;
                    for (auto v : st[vl]) {
                        st[ul].insert(v);
                    }
                }
            }
        } else {
            int v, k;
            cin >> v >> k;
            --v;
            int vl = to[uf.leader(v)];
            if (st[vl].size() < k) {
                ans.push_back(-1);
                continue;
            }
            auto it = st[vl].end();
            REP(j, k) { --it; }
            ans.push_back((*it) + 1);
        }
    }
    REP(i, ans.size()) output(ans[i]);
}
