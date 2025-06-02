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
    map<pair<int, int>, bool> mp;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        mp[{a, b}] = true;
        mp[{b, a}] = true;
    }
    // A
    int h = n / 2;
    vector<int> filterA(h, 0);
    REP(i, h) {
        REP(j, h) {
            if (mp.find({i, j}) != mp.end()) {
                filterA[i] |= 1 << j;
            }
        }
    }
    // B
    vector<int> filterB(n - h, 0);
    REP(i, n - h) {
        REP(j, n - h) {
            if (mp.find({i + h, j + h}) != mp.end()) {
                filterB[i] |= 1 << j;
            }
        }
    }
    // メイン
    vector<int> dp(1 << h, 0);
    REP(bit, 1 << h) {
        int mask = 0;
        REP(i, h) {
            if (bit & (1 << i)) {
                mask |= filterA[i];  // ビットが立っているやつがダメ
            }
        }
        if (bit & mask) continue;  // ビットが立っていたらダメ
        dp[bit] = __builtin_popcount(bit);
    }
    REP(bit, 1 << h) {
        REP(i, h) {
            if (bit & (1 << i)) continue;
            chmax(dp[bit | 1 << i], dp[bit]);
        }
    }
    // 前計算
    vector<int> filterC(n - h, 0);
    REP(i, n - h) {
        REP(j, h) {
            if (mp.find({i + h, j}) != mp.end()) {
                filterC[i] |= 1 << j;
            }
        }
    }
    // もう一方
    int ans = 0;
    REP(bit, 1 << (n - h)) {
        int mask = 0;
        REP(i, n - h) {
            if (bit & (1 << i)) {
                mask |= filterB[i];
            }
        }
        if (bit & mask) continue;
        // bitからAグループの最大を考える
        int mask2 = 0;
        REP(i, n - h) {
            if (bit & (1 << i)) {
                mask2 |= filterC[i];
            }
        }
        REP(i, h) {
            if (mask2 & (1 << i)) {
                mask2 &= ~(1 << i);
            } else {
                mask2 |= 1 << i;
            }
        }
        chmax(ans, dp[mask2] + __builtin_popcount(bit));
    }
    output(ans);
}
