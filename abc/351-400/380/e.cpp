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
    vector<int> ans;
    dsu uf(n);
    vector<int> left(n), right(n), color(n), cnt(n, 1);
    REP(i, n) left[i] = right[i] = color[i] = i;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, c;
            cin >> x >> c;
            --x, --c;
            int rootM = uf.leader(x);
            int leftM = left[rootM];
            int rightM = right[rootM];
            int colorM = color[rootM];
            cnt[colorM] -= uf.size(x);
            cnt[c] += uf.size(x);
            if (leftM - 1 >= 0) {
                int rootL = uf.leader(leftM - 1);
                int leftL = left[rootL];
                int rightL = right[rootL];
                int colorL = color[rootL];
                if (colorL == c) {
                    uf.merge(x, leftM - 1);
                    leftM = leftL;
                }
            }
            if (rightM + 1 < n) {
                int rootR = uf.leader(rightM + 1);
                int leftR = left[rootR];
                int rightR = right[rootR];
                int colorR = color[rootR];
                if (colorR == c) {
                    uf.merge(x, rightM + 1);
                    rightM = rightR;
                }
            }
            // 色の更新を行う
            left[uf.leader(x)] = leftM;
            right[uf.leader(x)] = rightM;
            color[uf.leader(x)] = c;
        } else {
            int c;
            cin >> c;
            --c;
            ans.push_back(cnt[c]);
        }
    }
    REP(i, ans.size()) output(ans[i]);
}
