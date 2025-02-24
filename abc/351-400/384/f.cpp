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
    vector<int> odd, even;
    REP(i, n) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even.push_back(a);
        } else {
            odd.push_back(a);
        }
    }
    ll ans = 0;
    // 偶数
    vector<int> cnt2Beki(30, 0);
    int max2Beki = 536870912;  // 2^29
    REP(i, even.size()) {
        int tmp2Beki = max2Beki;
        RREP(j, 29) {
            if (even[i] % tmp2Beki == 0) {
                cnt2Beki[j]++;
                break;
            }
            tmp2Beki /= 2;
        }
    }
    REP(i, even.size()) {
        int x = even[i];
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            ++cnt;
        }
        int tmp2Beki = 1;
        REP(j, 30) {
            if (j <= cnt) {
                ans += (ll)even[i] / tmp2Beki * cnt2Beki[j];
            } else {
                ans += (ll)x * cnt2Beki[j];
            }
            tmp2Beki *= 2;
        }
    }
    // 奇数
    vector<map<int, pair<int, ll>>> cnt2amari(30);
    REP(i, odd.size()) {
        int tmp2Beki = 1;
        REP(j, 30) {
            cnt2amari[j][odd[i] % tmp2Beki].first++;
            cnt2amari[j][odd[i] % tmp2Beki].second += odd[i];
            tmp2Beki *= 2;
        }
        tmp2Beki = max2Beki;
        int cnt = 0;
        ll sum = 0;
        RREP(j, 29) {
            int x = odd[i] % tmp2Beki;
            int y = (tmp2Beki - x) % tmp2Beki;
            if (cnt2amari[j].find(y) != cnt2amari[j].end()) {
                ans += ((ll)odd[i] * (cnt2amari[j][y].first - cnt) +
                        (cnt2amari[j][y].second - sum)) /
                       tmp2Beki;
                cnt = cnt2amari[j][y].first;
                sum = cnt2amari[j][y].second;
            }
            tmp2Beki /= 2;
        }
    }
    // 奇遇
    ll tmpOdd = 0;
    REP(i, odd.size()) { tmpOdd += odd[i]; }
    ans += tmpOdd * even.size();
    ll tmpEven = 0;
    REP(i, even.size()) { tmpEven += even[i]; }
    ans += tmpEven * odd.size();
    output(ans);
}
