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
int op(int a, int b) { return min(a, b); }

int e() { return INF32; }

int solve(int n, const vector<int> &s) {
    vector<int> t;
    REP(i, 1, n - 1) t.push_back(s[i]);
    sort(ALL(t));
    vector<int> a(n);
    a[0] = s[0];
    REP(i, 1, n - 1) a[i] = t[i - 1];
    a[n - 1] = s[n - 1];
    // メイン処理
    segtree<int, op, e> seg(n);
    seg.set(0, 1);
    REP(i, 1, n) {
        int ans = INF32;
        // 0から倒れる場合
        if (a[0] * 2 >= a[i]) {
            chmin(ans, 2);
        }
        // それ以外から倒れる場合
        auto it = lower_bound(a.begin() + 1, a.begin() + i, (a[i] + 1) / 2);
        int l = it - a.begin();
        chmin(ans, seg.prod(l, i) + 1);
        seg.set(i, ans);
    }
    int ans = seg.get(n - 1);
    return ans == INF32 ? -1 : ans;
}

int main() {
    int t;
    cin >> t;
    vector<int> ans(t);
    REP(i, t) {
        int n;
        cin >> n;
        vector<int> s(n);
        REP(i, n) cin >> s[i];
        ans[i] = solve(n, s);
    }
    REP(i, t) output(ans[i]);
}
