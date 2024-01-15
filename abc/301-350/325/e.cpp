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
using P = pair<ll, int>;

int main() {
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    vector d(n, vector<ll>(n));
    REP(i, n) REP(j, n) cin >> d[i][j];
    // S->i,j | 社用車
    vector<ll> distS(n, INF64);
    distS[0] = 0;
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [vc, v] = pq.top();
            pq.pop();
            if (vc > distS[v]) continue;
            REP(u, n) {
                if (u == v) continue;
                if (chmin(distS[u], distS[v] + d[v][u] * a)) {
                    pq.push({distS[u], u});
                }
            }
        }
    }
    // G->i,j | 電車
    vector<ll> distG(n, INF64);
    distG[n - 1] = 0;
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, n - 1});
        while (!pq.empty()) {
            auto [vc, v] = pq.top();
            pq.pop();
            if (vc > distG[v]) continue;
            REP(u, n) {
                if (u == v) continue;
                if (chmin(distG[u], distG[v] + d[v][u] * b + c)) {
                    pq.push({distG[u], u});
                }
            }
        }
    }
    // 答えを計算
    ll ans = INF64;
    REP(i, n) { chmin(ans, distS[i] + distG[i]); }
    output(ans);
}
