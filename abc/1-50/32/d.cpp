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
    int n, w;
    cin >> n >> w;
    vector<int> value(n), weight(n);
    REP(i, n) cin >> value[i] >> weight[i];
    vector<pair<int, int>> even, odd;
    REP(i, n) {
        if (i % 2 == 0)
            even.emplace_back(weight[i], value[i]);
        else
            odd.emplace_back(weight[i], value[i]);
    }
    auto f = [&](const vector<pair<int, int>> &v) -> vector<pair<ll, ll>> {
        int m = v.size();
        vector<pair<ll, ll>> ans;
        REP(bit, 1 << m) {
            ll sumV = 0, sumW = 0;
            REP(i, m) {
                if (bit & (1 << i)) {
                    sumV += v[i].second;
                    sumW += v[i].first;
                }
            }
            ans.emplace_back(sumW, sumV);
        }
        return ans;
    };
    auto a = f(even);
    auto b = f(odd);
    sort(ALL(b));
    vector<ll> mx(b.size());
    ll tmp = -1;
    REP(i, b.size()) {
        chmax(tmp, b[i].second);
        mx[i] = tmp;
    }
    ll ans = 0;
    for (auto [weightA, valueA] : a) {
        auto it = upper_bound(ALL(b), make_pair(w - weightA, INF64));
        if (it == b.begin()) continue;
        --it;
        chmax(ans, valueA + mx[it - b.begin()]);
    }
    output(ans);
}
