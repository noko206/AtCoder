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
template <class T> vector<T> enum_divisors(T n) {
    vector<T> ans;
    for (T i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    ll n;
    cin >> n;
    auto d = enum_divisors(n);
    set<ll> st;
    for (ll x : d) st.insert(x);
    map<ll, ll> mp;
    for (ll x : d) {
        string s = to_string(x);
        bool is_ok = true;
        REP(i, s.length()) {
            if (s[i] == '0') {
                is_ok = false;
                break;
            }
        }
        if (!is_ok) continue;
        string t = s;
        reverse(ALL(t));
        ll y = stoll(t);
        if (st.find(y) != st.end()) {
            mp[x] = y;
        }
    }
    map<ll, string> dp;
    auto dfs = [&](auto &dfs, ll n) -> string {
        assert(n > 0);
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        if (mp.find(n) != mp.end() && n == mp[n]) {
            return dp[n] = to_string(n);
        }
        for (ll x : d) {
            if (x == 1) continue;
            if (mp.find(x) == mp.end()) continue;
            if (n % (x * mp[x]) != 0) continue;
            string s = dfs(dfs, n / (x * mp[x]));
            if (s == "") continue;
            return dp[n] = to_string(x) + "*" + s + "*" + to_string(mp[x]);
        }
        return dp[n] = "";
    };
    string ans = dfs(dfs, n);
    if (ans == "") {
        output(-1);
    } else {
        output(ans);
    }
}
