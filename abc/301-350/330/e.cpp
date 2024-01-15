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
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<pair<int, int>> queries(q);
    REP(i, q) {
        int idx, x;
        cin >> idx >> x;
        queries[i] = {idx - 1, x};
    }
    // クエリ処理
    map<int, int> mp;
    fenwick_tree<int> ft(200005);
    REP(i, n) {
        ++mp[a[i]];
        if (mp[a[i]] == 1 && a[i] <= 200000) {
            ft.add(a[i], 1);
        }
    }
    vector<int> ans(q);
    REP(i, q) {
        auto [idx, x] = queries[i];
        // 前
        --mp[a[idx]];
        if (mp[a[idx]] == 0 && a[idx] <= 200000) {
            ft.add(a[idx], -1);
        }
        a[idx] = x;
        // 後
        ++mp[x];
        if (mp[x] == 1 && x <= 200000) {
            ft.add(x, 1);
        }
        // mex
        int ok = 200000;
        int ng = -1;
        while (ok - ng != 1) {
            int mid = (ok + ng) / 2;
            if (ft.sum(0, mid + 1) - 1 < mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans[i] = ok;
    }
    REP(i, q) output(ans[i]);
}
