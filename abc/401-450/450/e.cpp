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
    CumulativeSum(int n) : n(n), data(n + 1, 0) {};
    CumulativeSum(const vector<T>& v) : n((int)v.size()) {
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
    string x, y;
    cin >> x >> y;
    int a = x.length();
    int b = y.length();
    vector<ll> fib;
    fib.push_back(a);
    fib.push_back(b);
    ll sum = a + b;
    while (true) {
        int i = fib.size() - 1;
        if (sum >= INF64 - fib[i - 1] - fib[i - 2]) break;
        fib.push_back(fib[i - 1] + fib[i - 2]);
        sum += fib[i];
    }
    CumulativeSum<ll> csF(fib);
    csF.build();
    vector csX(26, CumulativeSum<int>(a + 1));
    vector csY(26, CumulativeSum<int>(b + 1));
    REP(i, a) csX[x[i] - 'a'].add(i, 1);
    REP(i, b) csY[y[i] - 'a'].add(i, 1);
    REP(i, 26) csX[i].build();
    REP(i, 26) csY[i].build();
    vector fib2(26, vector<ll>(fib.size()));
    REP(i, 26) {
        fib2[i][0] = csX[i].sum(0, a);
        fib2[i][1] = csY[i].sum(0, b);
    }
    REP(i, 26) {
        REP(j, 2, fib.size()) fib2[i][j] += fib2[i][j - 1] + fib2[i][j - 2];
    }
    vector csF2(26, CumulativeSum<ll>(fib.size()));
    REP(i, 26) {
        CumulativeSum<ll> tmp(fib2[i]);
        tmp.build();
        csF2[i] = tmp;
    }
    REP(i, fib.size()) {}
    auto f = [&](auto& f, ll k, int c) -> ll {
        if (k <= b) {
            return csY[c].sum(0, k);
        }
        ll sum = csY[c].sum(0, b);
        k -= b;
        if (k <= a) {
            return sum + csX[c].sum(0, k);
        }
        int ok = 0, ng = fib.size() + 1;
        while (ng - ok != 1) {
            int mid = (ok + ng) / 2;
            if (csF.sum(0, mid) <= k) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        assert(ok >= 2);
        sum += csF2[c].sum(0, ok);
        k -= csF.sum(0, ok);
        assert(k >= 0);
        return sum + f(f, k, c);
    };
    int q;
    cin >> q;
    vector<ll> ans(q);
    REP(i, q) {
        ll l, r;
        cin >> l >> r;
        char c;
        cin >> c;
        ans[i] = f(f, r, c - 'a') - f(f, l - 1, c - 'a');
        output(f(f, r, c - 'a'), f(f, l - 1, c - 'a'));
    }
    REP(i, q) output(ans[i]);
}
