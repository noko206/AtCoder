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
    vector<ll> f(n), s(n);
    REP(i, n) cin >> f[i] >> s[i], --f[i];
    vector<vector<ll>> x(n);
    REP(i, n) x[f[i]].push_back(s[i]);
    ll ans = 0;
    REP(i, n) {
        sort(ALL(x[i]));
        int m = x[i].size();
        if (m <= 1) continue;
        chmax(ans, x[i][m - 1] + x[i][m - 2] / 2);
    }
    multiset<ll> st;
    REP(i, n) {
        int m = x[i].size();
        if (m == 0) continue;
        st.insert(x[i][m - 1]);
    }
    if (st.size() >= 2) {
        REP(i, n) {
            int m = x[i].size();
            if (m == 0) continue;
            auto it = st.lower_bound(x[i][m - 1]);
            st.erase(it);
            int l = x[i][m - 1];
            auto itt = st.end();
            --itt;
            int r = *itt;
            chmax(ans, (ll)r + l);
            st.insert(x[i][m - 1]);
        }
    }
    output(ans);
}
