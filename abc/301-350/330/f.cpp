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
ll solve(const map<int, int> &mp, int r) {
    auto itL = mp.begin();
    auto itR = mp.end();
    --itR;
    auto [numLF, _tmpL] = *itL;
    auto [numRF, _tmpR] = *itR;
    ll ans = 0;
    int sumL = 0, sumR = 0, left = numLF, right = numRF;
    while (right - left > r) {
        auto [numL, cntL] = *itL;
        auto [numR, cntR] = *itR;
        if (sumL + cntL < sumR + cntR) {
            // 左側を詰める
            ++itL;
            auto [numLN, cntLN] = *itL;
            sumL += cntL;
            if (numR - numLN > r) {
                ans += (ll)(numLN - numL) * sumL;
            } else {
                ans += (ll)((numR - numL) - r) * sumL;
            }
            left = numLN;
        } else {
            // 右側を詰める
            --itR;
            auto [numRN, cntRN] = *itR;
            sumR += cntR;
            if (numRN - numL > r) {
                ans += (ll)(numR - numRN) * sumR;
            } else {
                ans += (ll)((numR - numL) - r) * sumR;
            }
            right = numRN;
        }
        if (ans > 1001001001001001) break;
    }
    return ans;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    map<int, int> mpX, mpY;
    REP(i, n) {
        ++mpX[x[i]];
        ++mpY[y[i]];
    }
    int ok = INF32;
    int ng = -1;
    while (ok - ng != 1) {
        int mid = (ok + ng) / 2;
        if (solve(mpX, mid) + solve(mpY, mid) <= k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    output(ok);
}
