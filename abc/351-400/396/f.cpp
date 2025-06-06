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
template <class T> long long inversion_number(const vector<T> &a) {
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    fenwick_tree<long long> ft((int)b.size());
    long long ans = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        int rank = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans += i - ft.sum(0, rank + 1);
        ft.add(rank, 1);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    // 前処理
    vector<vector<int>> pos(m);
    REP(i, n) pos[a[i]].push_back(i);
    // メイン処理
    ll num = inversion_number(a);
    vector<ll> ans;
    RREP(i, m - 1) {
        ans.push_back(num);
        REP(k, pos[i].size()) {
            int j = pos[i][k];
            num += j;
            num -= n - j - 1;
            // 調整
            num -= k;
            num += (int)pos[i].size() - k - 1;
        }
    }
    REP(i, m) output(ans[i]);
}
