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
    int h, w, n;
    cin >> h >> w >> n;
    vector<set<int>> hset(h), wset(w);
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        hset[x].insert(y);  // 行 => 列
        wset[y].insert(x);  // 列 => 行
    }
    int q;
    cin >> q;
    vector<int> ans(q);
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;
            ans[i] = hset[x].size();
            for (int y : hset[x]) {
                auto it = wset[y].lower_bound(x);
                wset[y].erase(it);
            }
            hset[x].clear();
        } else {
            int y;
            cin >> y;
            --y;
            ans[i] = wset[y].size();
            for (int x : wset[y]) {
                auto it = hset[x].lower_bound(y);
                hset[x].erase(it);
            }
            wset[y].clear();
        }
    }
    REP(i, q) output(ans[i]);
}
