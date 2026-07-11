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
    vector<string> s(n);
    vector<int> v(n);
    REP(i, n) cin >> s[i] >> v[i];
    // 前処理
    map<string, int> mp;
    REP(i, n) mp[s[i]] = v[i];
    int m = 1000000;
    vector<ll> tot(m, 0);
    RREP(i, m - 1) {
        char t[6];
        sprintf(t, "%06d", i);
        if (mp.find(t) != mp.end()) {
            tot[i] += mp[t];
        }
        REP(j, 6) {
            string tmp = t;
            if (tmp[j] == '0') continue;
            tmp[j] = tmp[j] - 1;
            int key = 0;
            REP(k, 6) {
                key *= 10;
                key += tmp[k] - '0';
            }
            tot[key] += tot[i];
        }
    }
    // クエリ
    int q;
    cin >> q;
    REP(i, q) {
        string x, y;
        cin >> x >> y;
    }
    output(tot[0]);
}
