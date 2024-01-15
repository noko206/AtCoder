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
    string s, t;
    cin >> s >> t;
    map<string, bool> mp1, mp2;
    {
        mp1["AB"] = true;
        mp1["BA"] = true;
        mp1["BC"] = true;
        mp1["CB"] = true;
        mp1["CD"] = true;
        mp1["DC"] = true;
        mp1["DE"] = true;
        mp1["ED"] = true;
        mp1["EA"] = true;
        mp1["AE"] = true;
    }
    {
        mp2["AC"] = true;
        mp2["AD"] = true;
        mp2["BD"] = true;
        mp2["BE"] = true;
        mp2["CE"] = true;
        mp2["CA"] = true;
        mp2["DA"] = true;
        mp2["DB"] = true;
        mp2["EB"] = true;
        mp2["EC"] = true;
    }
    bool is_ok = false;
    if (mp1.find(s) != mp1.end() && mp1.find(t) != mp1.end()) is_ok = true;
    if (mp2.find(s) != mp2.end() && mp2.find(t) != mp2.end()) is_ok = true;
    YesNo(is_ok);
}
