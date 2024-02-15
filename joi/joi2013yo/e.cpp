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
template <typename T> unordered_map<T, int> compress(vector<T> &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)a.size(); ++i) {
        comp[a[i]] = i;
    }
    return comp;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x1(n), y1(n), d1(n), x2(n), y2(n), d2(n), x, y, d;
    REP(i, n) {
        cin >> x1[i] >> y1[i] >> d1[i] >> x2[i] >> y2[i] >> d2[i];
        x.push_back(x1[i]);
        x.push_back(x2[i]);
        y.push_back(y1[i]);
        y.push_back(y2[i]);
        d.push_back(d1[i]);
        d.push_back(d2[i]);
    }
    auto compX = compress(x);
    auto compY = compress(y);
    auto compD = compress(d);
    vector cnt(3 * n, vector(3 * n, vector<int>(3 * n, 0)));
    REP(i, n) {
        REP(a, compX[x1[i]], compX[x2[i]]) {
            REP(b, compY[y1[i]], compY[y2[i]]) {
                REP(c, compD[d1[i]], compD[d2[i]]) { ++cnt[a][b][c]; }
            }
        }
    }
    ll ans = 0;
    REP(a, compX.size() - 1) {
        REP(b, compY.size() - 1) {
            REP(c, compD.size() - 1) {
                if (cnt[a][b][c] >= k) {
                    ll tmp = 1;
                    tmp *= (ll)(x[a + 1] - x[a]);
                    tmp *= (ll)(y[b + 1] - y[b]);
                    tmp *= (ll)(d[c + 1] - d[c]);
                    ans += tmp;
                }
            }
        }
    }
    output(ans);
}
