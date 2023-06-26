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
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

using mint = modint998244353;

template <class T>
vector<T> enum_divisors(T n) {
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

// clang-format on
int main() {
    int n;
    string s;
    cin >> n >> s;
    auto d = enum_divisors(n);
    map<int, mint> ans;
    for (int v : d) {
        if (v == n) break;
        mint tmp = 1;
        REP(i, v) {
            bool has_dot = false;
            REP(j, n / v) {
                if (s[i + j * v] == '.') {
                    has_dot = true;
                }
            }
            if (!has_dot) {
                tmp *= 2;
            }
        }
        auto d2 = enum_divisors(v);
        for (int u : d2) {
            if (u == v) break;
            tmp -= ans[u];
        }
        ans[v] = tmp;
    }
    mint sum = 0;
    for (auto [_, v] : ans) {
        sum += v;
    }
    output(sum.val());
}