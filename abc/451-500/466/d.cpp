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
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> rc, cr;
    REP(i, m) {
        int r, c;
        cin >> r >> c;
        while (true) {
            auto itR = rc.lower_bound({r, -1});
            if (itR == rc.end()) break;
            auto [_r, _c] = *itR;
            if (_r != r) break;
            rc.erase(itR);
            auto itC = cr.lower_bound({_c, _r});
            assert(itC != cr.end());
            cr.erase(itC);
        }
        while (true) {
            auto itC = cr.lower_bound({c, -1});
            if (itC == cr.end()) break;
            auto [_c, _r] = *itC;
            if (_c != c) break;
            cr.erase(itC);
            auto itR = rc.lower_bound({_r, _c});
            assert(itR != rc.end());
            rc.erase(itR);
        }
        rc.insert({r, c});
        cr.insert({c, r});
        assert(rc.size() == cr.size());
    }
    output(rc.size());
}
