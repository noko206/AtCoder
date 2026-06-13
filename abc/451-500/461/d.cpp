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
template <class T> struct CumulativeSum2d {
   public:
    CumulativeSum2d(int h, int w)
        : h(h), w(w), data(h + 1, vector<T>(w + 1, 0)) {};
    CumulativeSum2d(const vector<vector<T>>& v)
        : h((int)v.size()), w((int)v[0].size()) {
        data.resize(h + 1);
        data[0].resize(w + 1, 0);
        for (int i = 0; i < h; ++i) {
            data[i + 1].resize(w + 1, 0);
            for (int j = 0; j < w; ++j) {
                data[i + 1][j + 1] = v[i][j];
            }
        }
    };

    void add(int i, int j, T x) {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        data[i + 1][j + 1] += x;
    }

    void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i + 1][j + 1] +=
                    data[i + 1][j] + data[i][j + 1] - data[i][j];
            }
        }
    }

    // [si, gi), [sj, gj)
    T sum(int si, int sj, int gi, int gj) {
        assert(0 <= si && si <= gi && gi <= h);
        assert(0 <= sj && sj <= gj && gj <= w);
        return data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj];
    }

   private:
    int h, w;
    vector<vector<T>> data;
};

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    REP(i, h) cin >> s[i];
    CumulativeSum2d<int> cs(h, w);
    REP(i, h) {
        REP(j, w) {
            if (s[i][j] == '1') {
                cs.add(i, j, 1);
            }
        }
    }
    cs.build();
    ll ans = 0;
    REP(r1, h) REP(c1, w) REP(r2, r1, h) {
        int lower_bound;
        {
            int ok = w;
            int ng = c1 - 1;
            while (ok - ng != 1) {
                int mid = (ok + ng) / 2;
                if (cs.sum(r1, c1, r2 + 1, mid + 1) >= k) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            lower_bound = ok;
        }
        int upper_bound;
        {
            int ok = w;
            int ng = c1 - 1;
            while (ok - ng != 1) {
                int mid = (ok + ng) / 2;
                if (cs.sum(r1, c1, r2 + 1, mid + 1) > k) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            upper_bound = ok;
        }
        // output(upper_bound, lower_bound);
        ans += upper_bound - lower_bound;
    }
    output(ans);
}
