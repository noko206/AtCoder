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
vector<pair<int, int>> f(vector<pair<int, int>> a, int x) {
    vector<pair<int, int>> ans, even, odd;
    REP(i, a.size()) {
        if (i % 2 == 0) {
            even.emplace_back(a[i].first, a[i].second);
        } else {
            odd.emplace_back(a[i].first, a[i].second);
        }
    }
    vector<pair<ll, int>> even_bit, odd_bit;
    REP(bit, 1 << even.size()) {
        ll sum = 0;
        REP(i, even.size()) {
            if (bit & (1 << i)) {
                sum += even[i].first;
            } else {
                sum -= even[i].first;
            }
        }
        even_bit.emplace_back(sum, bit);
    }
    REP(bit, 1 << odd.size()) {
        ll sum = 0;
        REP(i, odd.size()) {
            if (bit & (1 << i)) {
                sum += odd[i].first;
            } else {
                sum -= odd[i].first;
            }
        }
        odd_bit.emplace_back(sum, bit);
    }
    sort(ALL(odd_bit));
    for (auto [v, bit] : even_bit) {
        auto it = lower_bound(ALL(odd_bit), make_pair(x - v, -1));
        if (it == odd_bit.end()) continue;
        auto [_v, _bit] = *it;
        if (v + _v == x) {
            REP(i, even.size()) {
                if (bit & (1 << i)) {
                    ans.emplace_back(even[i].first, even[i].second);
                } else {
                    ans.emplace_back(-even[i].first, even[i].second);
                }
            }
            REP(i, odd.size()) {
                if (_bit & (1 << i)) {
                    ans.emplace_back(odd[i].first, odd[i].second);
                } else {
                    ans.emplace_back(-odd[i].first, odd[i].second);
                }
            }
            break;
        }
    }
    return ans;
}

int main() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    REP(i, 3) a.push_back(0);
    vector<pair<int, int>> even, odd;
    REP(i, a.size()) {
        if (i % 2 == 0) {
            even.emplace_back(a[i], i);
        } else {
            odd.emplace_back(a[i], i);
        }
    }
    auto ansY = f(even, y);
    auto ansX = f(odd, x);
    if (ansY.size() > 0 && ansX.size() > 0) {
        output("Yes");
        vector<int> b(n + 3);
        for (auto [v, i] : ansY) {
            b[i] = v;
        }
        for (auto [v, i] : ansX) {
            b[i] = v;
        }
        string ans = "";
        char now = 'R';
        REP(i, n) {
            if (i % 2 == 0) {
                if (b[i] > 0) {
                    ans += now == 'R' ? 'L' : 'R';
                    now = 'U';
                } else {
                    ans += now == 'R' ? 'R' : 'L';
                    now = 'D';
                }
            } else {
                if (b[i] > 0) {
                    ans += now == 'U' ? 'R' : 'L';
                    now = 'R';
                } else {
                    ans += now == 'U' ? 'L' : 'R';
                    now = 'L';
                }
            }
        }
        output(ans);
    } else {
        output("No");
    }
}
