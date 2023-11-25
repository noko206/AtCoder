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

ll solve(const vector<int> &x, ll y) {
    int n = x.size();
    ll ans = INF64;
    vector<ll> tot(n + 1, 0);
    REP(i, n) tot[i + 1] = tot[i] + x[i];
    REP(i, n) {
        // 左側
        {
            ll l = x[i] - y;
            ll r = x[i];
            ll sum = 0;
            {
                auto it = upper_bound(ALL(x), r);
                if (it != x.end()) {
                    int idx = it - x.begin();
                    sum += tot[n] - tot[idx] - (n - idx) * r;
                }
            }
            {
                auto it = lower_bound(ALL(x), l);
                if (it != x.begin()) {
                    --it;
                    int idx = it - x.begin();
                    sum += l * (idx + 1) - tot[idx];
                }
            }
            assert(sum >= 0);
            chmin(ans, sum);
        }
        // 右側
        {
            ll l = x[i];
            ll r = x[i] + y;
            ll sum = 0;
            {
                auto it = upper_bound(ALL(x), r);
                if (it != x.end()) {
                    int idx = it - x.begin();
                    sum += tot[n] - tot[idx] - (n - idx) * r;
                }
            }
            {
                auto it = lower_bound(ALL(x), l);
                if (it != x.begin()) {
                    --it;
                    int idx = it - x.begin();
                    sum += l * (idx + 1) - tot[idx];
                }
            }
            assert(sum >= 0);
            chmin(ans, sum);
        }
    }
    return ans;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    sort(ALL(x));
    sort(ALL(y));
    if (n == 1) {
        output(0);
        return 0;
    }
    ll ok = INF64;
    ll ng = -1;
    while (ok - ng != 1) {
        ll mid = (ok + ng) / 2;
        ll cntX = solve(x, mid);
        ll cntY = solve(y, mid);
        bool is_ok = true;
        if (cntX > k || cntY > k)
            is_ok = false;
        else if (cntX + cntY > k)
            is_ok = false;
        if (is_ok) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    output(ok);
}
