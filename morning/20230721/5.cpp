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
    int n;
    cin >> n;
    vector<int> r(n), c(n), x(n);
    REP(i, n) cin >> r[i] >> c[i] >> x[i];
    map<int, ll> col;
    REP(i, n) { col[c[i]] += x[i]; }
    map<int, ll> tmp_row;
    REP(i, n) { tmp_row[r[i]] += x[i]; }
    set<pair<ll, int>> row;
    for (auto [row_num, tot] : tmp_row) {
        row.insert({tot, row_num});
    }
    map<int, vector<int>> col_to_row;
    REP(i, n) { col_to_row[c[i]].push_back(r[i]); }
    map<pair<int, int>, int> rc;
    REP(i, n) { rc[{r[i], c[i]}] = x[i]; }
    ll ans = 0;
    for (auto [col_num, tot] : col) {
        vector<pair<ll, int>> fukugen;
        for (int row_num : col_to_row[col_num]) {
            auto it = row.lower_bound({tmp_row[row_num], row_num});
            row.insert({(*it).first - rc[{row_num, col_num}], row_num});
            fukugen.push_back({(*it).first - rc[{row_num, col_num}], row_num});
            row.erase(it);
        }
        auto it = row.end();
        --it;
        auto [tot_r, _] = *it;
        chmax(ans, tot + tot_r);
        for (auto [tot, row_num] : fukugen) {
            auto it = row.lower_bound({tot, row_num});
            row.insert({(*it).first + rc[{row_num, col_num}], row_num});
            row.erase(it);
        }
    }
    output(ans);
}
