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
    vector<tuple<int, int, int>> wuv(m);
    REP(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        wuv[i] = {w, u, v};
    }
    vector<int> a(k), b(k);
    REP(i, k) cin >> a[i], --a[i];
    REP(i, k) cin >> b[i], --b[i];
    sort(ALL(a));
    sort(ALL(b));

    // 処理
    sort(ALL(wuv));
    dsu uf(n);
    vector<int> cntA(n, 0), cntB(n, 0);
    REP(i, k) {
        cntA[a[i]]++;
        cntB[b[i]]++;
    }
    ll ans = 0;
    int cnt = 0;
    for (auto [w, u, v] : wuv) {
        if (uf.same(u, v)) continue;
        int ru = uf.leader(u);
        int rv = uf.leader(v);
        assert(!(cntA[ru] != 0 && cntB[ru] != 0));
        assert(!(cntA[rv] != 0 && cntB[rv] != 0));
        // if (cntA[ru] != 0 && cntB[ru] != 0) {
        //     output(w, u + 1, v + 1, cntA[ru], cntB[ru]);
        //     return 0;
        // }
        // if (cntA[rv] != 0 && cntB[rv] != 0) {
        //     output(w, u + 1, v + 1, cntA[rv], cntB[rv]);
        //     return 0;
        // }
        int x = min(cntA[ru], cntB[rv]);
        int y = min(cntB[ru], cntA[rv]);
        cnt += x + y;
        ans += (ll)w * (x + y);
        uf.merge(u, v);
        int r = uf.leader(u);
        cntA[ru] -= x;
        cntB[rv] -= x;
        cntB[ru] -= y;
        cntA[rv] -= y;
        cntA[r] = cntA[ru] + cntA[rv];
        cntB[r] = cntB[ru] + cntB[rv];
    }
    // assert(cnt == k);
    output(ans);
}
