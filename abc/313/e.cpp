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
using mint = modint998244353;

vector<pair<char, int>> run_length_encode(string s) {
    vector<pair<char, int>> ans;
    int i = 0, j = 0, n = s.length();
    while (i < n) {
        while (s[i] == s[j] && j < n) {
            ++j;
        }
        ans.push_back({s[i], j - i});
        i = j;
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    auto e = run_length_encode(s);
    bool is_ok = true;
    REP(i, e.size() - 1) {
        auto [c1, cnt1] = e[i];
        auto [c2, cnt2] = e[i + 1];
        if (c1 != '1' && c2 != '1') is_ok = false;
    }
    REP(i, e.size()) {
        auto [c, cnt] = e[i];
        if (c != '1' && cnt >= 2) is_ok = false;
    }
    if (!is_ok) {
        output(-1);
        return 0;
    }
    mint ans = 0;
    auto [c0, cnt0] = e[0];
    bool first_one = false;
    if (c0 == '1') {
        e.insert(e.begin(), {'a', 0});
        first_one = true;
    }
    auto [ce, cnte] = e[e.size() - 1];
    if (ce == '1') {
        ans += cnte;
        e.pop_back();
    }
    while (e.size() >= 2) {
        auto [cR, cntR] = e.back();
        e.pop_back();
        auto [cL, cntL] = e.back();
        e.pop_back();
        // 1ではない右端の数字を削除をカウント
        ++ans;
        mint one_cnt = cntL + ans * (cR - '0' - 1);
        ans += one_cnt;
    }
    if (first_one) --ans;
    output(ans.val());
}
