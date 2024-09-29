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
// LIS復元, LISの復元, LIS 復元
// LISの復元は配列の添え字を返す
template <class T> vector<T> LIS(const vector<T> &a, bool is_strong) {
    int n = (int)a.size();
    long long inf64 = 1001001001001001001;
    vector<long long> dp(n, inf64);
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        auto it = is_strong
                      // 狭義単調増加
                      ? lower_bound(dp.begin(), dp.end(), a[i])
                      // 広義単調増加
                      : upper_bound(dp.begin(), dp.end(), a[i]);
        pos.push_back(it - dp.begin());
        *it = a[i];
    }
    int lis = lower_bound(dp.begin(), dp.end(), inf64) - dp.begin();
    vector<int> subseq(lis);
    int si = subseq.size() - 1;
    int pi = pos.size() - 1;
    while (0 <= si && 0 <= pi) {
        if (pos[pi] == si) {
            subseq[si] = pi;
            --si;
        }
        --pi;
    }
    return subseq;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> rc(n);
    REP(i, n) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        rc[i] = {r, c};
    }
    rc.emplace_back(0, 0);
    rc.emplace_back(h - 1, w - 1);
    sort(ALL(rc));
    vector<int> a;
    for (auto [r, c] : rc) {
        a.push_back(c);
    }
    auto lis = LIS(a, false);
    string ans = "";
    int now = 1;
    int y = 0, x = 0;
    bool is_first = true;
    for (auto [r, c] : rc) {
        if (is_first) {
            is_first = false;
            continue;
        }
        if (c != a[lis[now]]) {
            continue;
        }
        while (y != r) {
            ans += 'D';
            ++y;
        }
        while (x != c) {
            ans += 'R';
            ++x;
        }
        ++now;
        if (now == lis.size()) {
            break;
        }
    }
    output(lis.size() - 2);
    output(ans);
}
