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
bool solve(int n, const vector<int> &a) {
    vector<ll> b(n);
    REP(i, n) b[i] = abs(a[i]);
    sort(ALL(b));
    ll bunshi = b[1];
    ll bunbo = b[0];
    REP(i, n - 1) {
        ll tmp = b[i] * bunshi;
        if (tmp % bunbo != 0) {
            return false;
        }
        tmp /= bunbo;
        if (tmp != b[i + 1]) {
            return false;
        }
    }
    map<int, int> plus_, minus_;
    REP(i, n) {
        if (a[i] > 0) {
            plus_[abs(a[i])]++;
        } else {
            minus_[abs(a[i])]++;
        }
    }
    if (plus_.empty() || minus_.empty()) {
        return true;
    }
    // プラススタートの場合
    bool ok_plus = true;
    {
        auto plus = plus_;
        auto minus = minus_;
        REP(i, n) {
            if (i % 2 == 0) {
                --plus[b[i]];
                if (plus[b[i]] < 0) {
                    ok_plus = false;
                }
            } else {
                --minus[b[i]];
                if (minus[b[i]] < 0) {
                    ok_plus = false;
                }
            }
        }
    }
    // マイナススタートの場合
    bool ok_minus = true;
    {
        auto plus = plus_;
        auto minus = minus_;
        REP(i, n) {
            if (i % 2 == 0) {
                --minus[b[i]];
                if (minus[b[i]] < 0) {
                    ok_minus = false;
                }
            } else {
                --plus[b[i]];
                if (plus[b[i]] < 0) {
                    ok_minus = false;
                }
            }
        }
    }
    return ok_plus || ok_minus;
}

int main() {
    int t;
    cin >> t;
    vector<bool> ans(t);
    REP(i, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(j, n) cin >> a[j];
        ans[i] = solve(n, a);
    }
    REP(i, t) YesNo(ans[i]);
}
