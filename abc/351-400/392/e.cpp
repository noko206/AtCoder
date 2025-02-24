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
    vector<tuple<int, int, int>> t;
    dsu uf(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (uf.same(a, b)) {
            t.emplace_back(a, b, i + 1);
        } else {
            uf.merge(a, b);
        }
    }
    auto groups = uf.groups();
    set<int> st;  // baseに含まれないもの
    REP(i, n) st.insert(i);
    for (int v : groups[0]) {
        st.erase(v);
    }
    map<int, vector<int>> mp;
    for (auto g : groups) {
        int v = uf.leader(g[0]);
        mp[v] = g;
    }
    int base = groups[0][0];           // baseに含まれる頂点
    vector<tuple<int, int, int>> ans;  // ケーブルの番号, つなぐ前、つないだ後
    for (auto [a, b, num] : t) {
        // 連結ならループを抜ける
        if (uf.size(0) == n) break;
        if (uf.same(a, base) && uf.same(b, base)) {
            // 両方baseに含まれる
            int v = *st.begin();
            ans.emplace_back(num, a + 1, v + 1);
            int leader = uf.leader(v);
            for (int u : mp[leader]) {
                st.erase(u);
            }
            uf.merge(v, base);
        } else {
            // 両方ともbaseに含まれない
            ans.emplace_back(num, a + 1, base + 1);
            int leader = uf.leader(a);
            for (int u : mp[leader]) {
                st.erase(u);
            }
            uf.merge(a, base);
        }
    }
    output(ans.size());
    for (auto [a, b, c] : ans) {
        output(a, b, c);
    }
}
