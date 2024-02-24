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
template <class T> vector<pair<T, int>> prime_factorize(T n) {
    vector<pair<T, int>> ans;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        T e = 0;
        while (n % i == 0) {
            ++e;
            n /= i;
        }
        ans.push_back({i, e});
    }
    if (n != 1) ans.push_back({n, 1});
    return ans;
}

int main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    ll ans = 0;
    REP(i, n) {
        int a;
        cin >> a;
        if (a == 0) {
            ans += i;
            ++cnt[a];
            continue;
        }
        if (cnt.find(0) != cnt.end()) ans += cnt[0];
        ll mn = 1;
        auto pf = prime_factorize(a);
        for (auto [p, c] : pf) {
            if (c % 2 == 0) continue;
            mn *= p;
        }
        ll num = 1;
        while (mn <= 200000) {
            if (cnt.find(mn) != cnt.end()) {
                ans += cnt[mn];
            }
            mn /= num * num;
            ++num;
            mn *= num * num;
        }
        ++cnt[a];
    }
    output(ans);
}