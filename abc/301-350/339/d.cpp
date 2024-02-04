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
int dist[60][60][60][60];
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector<int> si, sj;
    REP(i, n) {
        REP(j, n) {
            if (s[i][j] == 'P') {
                si.push_back(i);
                sj.push_back(j);
            }
        }
    }
    REP(i, n) REP(j, n) REP(k, n) REP(l, n) dist[i][j][k][l] = INF32;
    dist[si[0]][sj[0]][si[1]][sj[1]] = 0;
    queue<tuple<int, int, int, int>> q;
    q.push({si[0], sj[0], si[1], sj[1]});
    while (!q.empty()) {
        auto [xi, xj, yi, yj] = q.front();
        q.pop();
        REP(i, 4) {
            int nxi = xi + di[i];
            int nxj = xj + dj[i];
            int nyi = yi + di[i];
            int nyj = yj + dj[i];
            if (nxi < 0 || nxj < 0 || nxi >= n || nxj >= n ||
                s[nxi][nxj] == '#') {
                nxi = xi;
                nxj = xj;
            }
            if (nyi < 0 || nyj < 0 || nyi >= n || nyj >= n ||
                s[nyi][nyj] == '#') {
                nyi = yi;
                nyj = yj;
            }
            if (chmin(dist[nxi][nxj][nyi][nyj], dist[xi][xj][yi][yj] + 1)) {
                q.push({nxi, nxj, nyi, nyj});
                if (nxi == nyi && nxj == nyj) {
                    output(dist[nxi][nxj][nyi][nyj]);
                    return 0;
                }
            }
        }
    }
    output(-1);
}
