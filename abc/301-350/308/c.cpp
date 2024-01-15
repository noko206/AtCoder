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

ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }

// clang-format on
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    map<pair<ll, ll>, vector<int>> mp1;
    vector<pair<double, pair<ll, ll>>> vec;
    REP(i, n) {
        ll g = gcd(a[i], a[i] + b[i]);
        if (mp1.find({a[i] / g, (a[i] + b[i]) / g}) != mp1.end()) {
            vec.push_back({-(a[i] / (double)(a[i] + b[i])),
                           {a[i] / g, (a[i] + b[i]) / g}});
        }
        mp1[{a[i] / g, (a[i] + b[i]) / g}].push_back(i + 1);
    }
    sort(ALL(vec));
    vector<int> ans;
    for (auto [_, p] : vec) {
        ll x = p.first;
        ll y = p.second;
        for (auto i : mp1[{x, y}]) {
            ans.push_back(i);
        }
    }
    output(ans);
}
