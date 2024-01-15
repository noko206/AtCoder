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
    string s;
    int q;
    cin >> n >> s >> q;
    vector<int> memo(n);
    int flg = 0;
    int pos = 0;
    REP(i, n) { memo[i] = true; }
    REP(i, q) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        --x;
        if (t == 1) {
            s[x] = c;
            memo.push_back(x);
        } else if (t == 2) {
            flg = 1;
            pos = memo.size();
        } else {
            flg = 2;
            pos = memo.size();
        }
    }
    unordered_map<int, bool> mp;
    REP(i, pos, memo.size()) { mp[memo[i]] = true; }
    string ans = "";
    if (flg == 0) {
        ans = s;
    } else if (flg == 1) {
        REP(i, n) {
            if (mp.find(i) == mp.end()) {
                ans += tolower(s[i]);
            } else {
                ans += s[i];
            }
        }
    } else if (flg == 2) {
        REP(i, n) {
            if (mp.find(i) == mp.end()) {
                ans += toupper(s[i]);
            } else {
                ans += s[i];
            }
        }
    }
    output(ans);
}
