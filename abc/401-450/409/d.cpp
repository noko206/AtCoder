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
string solve(int n, const string s) {
    string ans = "";
    REP(i, n) {
        if (i + 1 < n && s[i] > s[i + 1]) {
            int r = n;
            REP(j, i + 1, n) {
                if (s[i] < s[j]) {
                    r = j;
                    break;
                }
            }
            REP(j, i + 1, r) ans += s[j];
            ans += s[i];
            REP(j, r, n) ans += s[j];
            break;
        }
        ans += s[i];
    }
    return ans;
}

string naive(int n, const string s) {
    string ans = s;
    REP(l, n) {
        REP(r, l + 1, n) {
            string t = "";
            REP(i, l) { t += s[i]; }
            REP(i, l + 1, r + 1) { t += s[i]; }
            t += s[l];
            REP(i, r + 1, n) { t += s[i]; }
            chmin(ans, t);
        }
    }
    return ans;
}

void test() {
    int n = 5;
    REP(a, 26) REP(b, 26) REP(c, 26) REP(d, 26) REP(e, 26) {
        string s = "";
        s += (char)(a + 'a');
        s += (char)(b + 'a');
        s += (char)(c + 'a');
        s += (char)(d + 'a');
        s += (char)(e + 'a');
        string sol = solve(n, s);
        string nai = naive(n, s);
        if (sol != nai) {
            output(s, sol, nai);
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    vector<string> ans(t);
    REP(i, t) {
        int n;
        string s;
        cin >> n >> s;
        ans[i] = solve(n, s);
    }
    REP(i, t) output(ans[i]);
}
