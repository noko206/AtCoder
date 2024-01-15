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
template <typename T>
pair<unordered_map<T, int>, vector<T>> compress(const vector<T> &a) {
    auto decomp = a;
    sort(decomp.begin(), decomp.end());
    decomp.erase(unique(decomp.begin(), decomp.end()), decomp.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)decomp.size(); ++i) {
        comp[decomp[i]] = i;
    }
    return {comp, decomp};
}

ll op(ll a, ll b) { return a + b; }

ll e() { return 0; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    vector<pair<int, int>> c(n);
    auto [comp, decomp] = compress(b);
    REP(i, n) c[i] = {a[i], -comp[b[i]]};
    sort(ALL(c));
    segtree<ll, op, e> seg(n);
    ll ans = 0;
    REP(i, n) {
        auto [x, y] = c[i];
        y *= -1;
        int cnt = 1;
        while (i + 1 < n) {
            auto [nx, ny] = c[i + 1];
            ny *= -1;
            if (x == nx && y == ny) {
                ++i;
                ++cnt;
                continue;
            }
            break;
        }
        seg.set(y, seg.get(y) + cnt);
        ans += cnt * seg.prod(y, n);
    }
    output(ans);
}
