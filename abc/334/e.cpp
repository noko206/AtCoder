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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

using mint = modint998244353;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    dsu uf(h * w);
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == '.') continue;
            REP(k, 4) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if (s[ni][nj] == '.') continue;
                if (uf.same(i * w + j, ni * w + nj)) continue;
                uf.merge(i * w + j, ni * w + nj);
            }
        }
    }
    vector<bool> seen(h * w, false);
    int cnt = 0;
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == '.') continue;
            int r = uf.leader(i * w + j);
            if (seen[r]) continue;
            seen[r] = true;
            ++cnt;
        }
    }
    mint ans = 0;
    int red_cnt = 0;
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == '#') continue;
            ++red_cnt;
            int green_num = 0;
            set<int> st;
            REP(k, 4) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                if (s[ni][nj] == '.') continue;
                ++green_num;
                st.insert(uf.leader(ni * w + nj));
            }
            int root_num = st.size();
            if (green_num == 0) {
                ans += cnt + 1;
            } else {
                ans += cnt - (root_num - 1);
            }
        }
    }
    ans /= red_cnt;
    output(ans.val());
}
