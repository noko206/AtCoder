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
    cin >> n >> m;
    vector<int> a, b, c;
    REP(i, n) {
        int n, x;
        cin >> n >> x;
        if (n == 0) {
            a.push_back(x);
        } else if (n == 1) {
            b.push_back(x);
        } else {
            c.push_back(x);
        }
    }
    sort(ALLR(a));
    CumulativeSum<ll> cs(a.size());
    REP(i, a.size()) cs.add(i, (ll)a[i]);
    cs.build();
    sort(ALLR(b));
    sort(ALL(c));
    ll ans = cs.sum(0, min((int)a.size(), m));
    ll b_sum = 0;
    int c_cnt = 0;
    int c_nokori = 0;
    REP(i, b.size()) {
        if (c_nokori == 0) {
            if (c.size() == 0) break;
            c_nokori = c.back();
            c.pop_back();
            ++c_cnt;
        }
        b_sum += b[i];
        --c_nokori;
        if (m - (i + 1) - c_cnt < 0) break;
        chmax(ans, b_sum + cs.sum(0, min(m - (i + 1) - c_cnt, (int)a.size())));
    }
    output(ans);
}
