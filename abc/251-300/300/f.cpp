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
template <class T> struct CumulativeSum {
   public:
    CumulativeSum(int n) : n(n), data(n + 1, 0){};
    CumulativeSum(const vector<T> &v) : n((int)v.size()) {
        data.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            data[i + 1] = v[i];
        }
    };

    void add(int idx, T x) {
        assert(0 <= idx && idx < n);
        data[idx + 1] += x;
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            data[i + 1] += data[i];
        }
    }

    // [l, r)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return data[r] - data[l];
    }

   private:
    int n;
    vector<T> data;
};

int main() {
    int n, m;
    ll k;
    string s;
    cin >> n >> m >> k >> s;
    CumulativeSum<int> cs(n);
    REP(i, n) {
        if (s[i] == 'x') {
            cs.add(i, 1);
        }
    }
    cs.build();
    ll ans = 0;
    REP(l, n) {
        ll ok = l;
        ll ng = (ll)n * m + 1;
        while (ng - ok != 1) {
            ll mid = (ok + ng) / 2;
            ll w = mid / n * cs.sum(0, n) + cs.sum(0, (mid % n)) - cs.sum(0, l);
            if (w <= k) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        chmax(ans, ok - l);
    }
    output(ans);
}
