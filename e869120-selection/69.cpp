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
vector<int> enum_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    vector<int> ans;
    REP(i, n + 1) {
        if (is_prime[i]) ans.push_back(i);
    }
    return ans;
}

int main() {
    int q;
    cin >> q;
    auto primes = enum_primes(1000000);
    unordered_map<int, bool> mp;
    for (int p : primes) {
        mp[p] = true;
    }
    vector<int> tot(100005);
    REP(i, 100001) {
        if (mp.find(i) == mp.end()) continue;
        if (mp.find((i + 1) / 2) == mp.end()) continue;
        if (i % 2 == 0) continue;
        ++tot[i];
    }
    REP(i, 100000) { tot[i + 1] += tot[i]; }
    vector<int> ans(q);
    REP(i, q) {
        int l, r;
        cin >> l >> r;
        ans[i] = tot[r] - tot[l - 1];
    }
    REP(i, q) { output(ans[i]); }
}
