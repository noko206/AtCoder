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
// https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis
template <bool Strict, class Type>
std::vector<int> LIS(const std::vector<Type>& v, int def = -1) {
    std::vector<Type> dp;

    auto it = dp.begin();

    std::vector<int> positions;

    for (const auto& elem : v) {
        if constexpr (Strict) {
            it = std::lower_bound(dp.begin(), dp.end(), elem);
        } else {
            it = std::upper_bound(dp.begin(), dp.end(), elem);
        }

        positions.push_back(static_cast<int>(it - dp.begin()));

        if (it == dp.end()) {
            dp.push_back(elem);
        } else {
            if (def != -1 && it != dp.begin()) {
                *it = elem;
            }
        }
    }

    std::vector<int> subseq(dp.size());

    int si = static_cast<int>(subseq.size()) - 1;

    int pi = static_cast<int>(positions.size()) - 1;

    while ((0 <= si) && (0 <= pi)) {
        if (positions[pi] == si) {
            subseq[si] = pi;

            --si;
        }

        --pi;
    }

    return subseq;
}

int solve(int n, vector<int> p) {
    auto lis1 = LIS<true, int>(p, 0);
    map<int, bool> mp;
    for (int x : lis1) {
        mp[p[x]] = true;
    }
    vector<int> q;
    REP(i, n) {
        if (mp.find(p[i]) == mp.end()) {
            q.push_back(p[i]);
        }
    }
    auto lis2 = LIS<true, int>(q);
    int ans = (int)lis1.size() + (int)lis2.size();
    output(lis1);
    output(lis2);
    return ans;
}

int naive(int n, vector<int> p) {
    int ans = 0;
    REP(bit, 1 << n) {
        int x = 0, y = 0, c = 0;
        REP(i, n) {
            if (bit & (1 << i)) {
                if (chmax(x, p[i])) {
                    ++c;
                }
            } else {
                if (chmax(y, p[i])) {
                    ++c;
                }
            }
        }
        chmax(ans, c);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    REP(i, n) cin >> p[i];
    output(solve(n, p));
    // output(naive(n, p));
}
