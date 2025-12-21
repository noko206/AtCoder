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
template <class T> struct Imos2d {
   public:
    Imos2d(int h, int w) : h(h), w(w), data(h + 1, vector<T>(w + 1, 0)) {};

    // [si, gi), [sj, gj)
    void add(int si, int sj, int gi, int gj, T x) {
        assert(0 <= si && si <= gi && gi <= h);
        assert(0 <= sj && sj <= gj && gj <= w);
        data[si][sj] += x;
        data[si][gj] -= x;
        data[gi][sj] -= x;
        data[gi][gj] += x;
    }

    void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i + 1][j] += data[i][j];
            }
        }
        for (int j = 0; j < w; ++j) {
            for (int i = 0; i < h; ++i) {
                data[i][j + 1] += data[i][j];
            }
        }
    }

    T get(int i, int j) {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        return data[i][j];
    }

   private:
    int h, w;
    vector<vector<T>> data;
};

int main() {
    int n;
    cin >> n;
    Imos2d<int> cnt(2000, 2000);
    Imos2d<ll> type(2000, 2000);
    REP(i, n) {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        --u, --l;
        cnt.add(u, l, d, r, 1);
        type.add(u, l, d, r, i + 1);
    }
    cnt.build();
    type.build();
    int sum = 0;
    vector<int> d(n, 0);
    REP(i, 2000) {
        REP(j, 2000) {
            int c = cnt.get(i, j);
            if (c == 0) {
                ++sum;
            } else if (c == 1) {
                ++d[type.get(i, j) - 1];
            }
        }
    }
    REP(i, n) output(sum + d[i]);
}
