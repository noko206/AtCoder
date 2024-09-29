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
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    ll nokori = k;
    REP(i, n) cin >> a[i], nokori -= a[i];
    auto sortedA = a;
    sort(ALL(sortedA));
    vector<ll> ans(n);
    // BIT2つ
    vector<ll> bunshi(n + 1, 0);
    REP(i, n) { bunshi[i + 1] += bunshi[i] + sortedA[i]; }
    vector<pair<ll, int>> b(n);
    REP(i, n) b[i] = {a[i], i};
    sort(ALL(b));
    vector<int> to(n);
    REP(i, n) {
        auto [_, pos] = b[i];
        to[pos] = i;
    }
    // メイン
    REP(i, n) {
        ll ok = nokori + 1;
        ll ng = -1;
        while (ok - ng != 1) {
            ll mid = (ok + ng) / 2;
            auto it = upper_bound(ALL(sortedA), a[i] + mid);
            ll nokori2 = nokori - mid;
            int pos = it - sortedA.begin();
            if (n - pos >= m) {
                ng = mid;
                continue;
            }
            int ok2 = pos;
            int ng2 = -1;
            while (abs(ok2 - ng2) != 1) {
                int mid2 = (ok2 + ng2) / 2;
                ll bunboSum = pos - mid2;
                ll bunshiSum = bunshi[pos] - bunshi[mid2];
                if (mid2 <= to[i] && to[i] < pos) {
                    bunshiSum -= sortedA[to[i]];
                    bunboSum--;
                }
                if ((bunshiSum + nokori2) >= (a[i] + mid + 1) * bunboSum) {
                    ok2 = mid2;
                } else {
                    ng2 = mid2;
                }
            }
            int bunbo = n - ok2;
            if (ok2 <= to[i]) {
                bunbo--;
            }
            if (bunbo < m) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok == nokori + 1) {
            ans[i] = -1;
        } else {
            ans[i] = ok;
        }
    }
    output(ans);
}
