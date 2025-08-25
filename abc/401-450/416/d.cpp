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
ll naive(int n, int m, vector<int> a, vector<int> b) {
    sort(ALL(a));
    sort(ALL(b));
    vector<int> p(n);
    REP(i, n) p[i] = i;
    ll ans = INF64;
    do {
        ll sum = 0;
        REP(i, n) { sum += (a[p[i]] + b[i]) % m; }
        chmin(ans, sum);
    } while (next_permutation(ALL(p)));
    return ans;
}

ll solve(int n, int m, vector<int> a, vector<int> b) {
    REP(i, n) a[i] %= m, b[i] %= m;
    sort(ALL(a));
    sort(ALL(b));
    ll ans = 0;
    int pos = 1;
    REP(i, n) {
        if (a[i] + b[n - pos] >= m) {
            ans += (a[i] + b[n - pos]) % m;
            ++pos;
        } else {
            ans += a[i];
        }
    }
    RREP(i, n - pos) ans += b[i];
    return ans;
}

void test() {
    int n = 5;
    int m = 6;
    vector<int> a(n), b(n);
    REP(i, n) a[i] = rand() % m;
    REP(i, n) b[i] = rand() % m;
    ll naive_ = naive(n, m, a, b);
    ll solve_ = solve(n, m, a, b);
    sort(ALL(a));
    sort(ALL(b));
    output(naive_, solve_);
    if (naive_ != solve_) {
        output("===");
        output(n, m);
        output(a);
        output(b);
        output(naive_);
        output(solve_);
        output("");
        exit(0);
    }
}

int main() {
    int t;
    cin >> t;
    vector<ll> ans(t);
    REP(i, t) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        REP(i, n) cin >> a[i];
        REP(i, n) cin >> b[i];
        ans[i] = solve(n, m, a, b);
    }
    REP(i, t) output(ans[i]);
}