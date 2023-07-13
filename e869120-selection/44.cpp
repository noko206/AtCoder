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

int dp[1000000];
int dp_odd[1000000];

int main() {
    vector<int> three(1, 1), four(1, 1), four_odd(1, 1);
    REP(i, INF32) {
        if (three[i] + i + 2 >= 1000000) break;
        three.push_back(three[i] + i + 2);
    }
    REP(i, INF32) {
        if (four[i] + three[i + 1] >= 1000000) break;
        four.push_back(four[i] + three[i + 1]);
        if ((four[i] + three[i + 1]) % 2 == 1) {
            four_odd.push_back(four[i] + three[i + 1]);
        }
    }
    REP(i, 1000000) {
        dp[i] = INF32;
        dp_odd[i] = INF32;
    }
    dp[0] = 0;
    dp_odd[0] = 0;
    REP(i, four.size()) {
        REP(j, 1000000) {
            if (j - four[i] >= 0) {
                chmin(dp[j], dp[j - four[i]] + 1);
                chmin(dp[j], dp[j - four[i]] + 1);
            }
        }
    }
    REP(i, four_odd.size()) {
        REP(j, 1000000) {
            if (j - four_odd[i] >= 0) {
                chmin(dp_odd[j], dp_odd[j - four_odd[i]] + 1);
                chmin(dp_odd[j], dp_odd[j - four_odd[i]] + 1);
            }
        }
    }
    vector<pair<int, int>> ans;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        ans.push_back({dp[n], dp_odd[n]});
    }
    for (auto [x, y] : ans) {
        output(x, y);
    }
}
