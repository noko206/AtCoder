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
struct cumulative_sum {
   public:
    cumulative_sum(int n) : n(n), data(n + 1, 0){};

    void add(int idx, long long x) {
        assert(0 <= idx && idx < n);
        data[idx + 1] += x;
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            data[i + 1] += data[i];
        }
    }

    // [l, r)
    long long sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return data[r] - data[l];
    }

   private:
    int n;
    vector<long long> data;
};

int main() {
    int n;
    cin >> n;
    cumulative_sum cs(n);
    REP(i, n) {
        int a;
        cin >> a;
        cs.add(i, a);
    }
    cs.build();
    vector<ll> ans;
    REP(k, 1, n + 1) {
        ll tmp = 0;
        REP(i, n - k + 1) { chmax(tmp, cs.sum(i, i + k)); }
        ans.push_back(tmp);
    }
    REP(i, n) { output(ans[i]); }
}
