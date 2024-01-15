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
int mod = 998244353;

struct Hash {
    ll hash;
    ll base_pow;
};

Hash op(Hash l, Hash r) {
    Hash res;
    res.hash = (l.hash * r.base_pow + r.hash) % mod;
    res.base_pow = l.base_pow * r.base_pow % mod;
    return res;
}

Hash e() {
    Hash res;
    res.hash = 0;
    res.base_pow = 1;
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree<Hash, op, e> segL(n);
    segtree<Hash, op, e> segR(n);
    REP(i, n) {
        {
            Hash res;
            res.hash = s[i];
            res.base_pow = 100;
            segL.set(i, res);
        }
        {
            Hash res;
            res.hash = s[n - i - 1];
            res.base_pow = 100;
            segR.set(i, res);
        }
    }
    vector<bool> ans;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            char c;
            cin >> x >> c;
            --x;
            Hash res;
            res.hash = (int)c;
            res.base_pow = 100;
            segL.set(x, res);
            segR.set(n - x - 1, res);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            ans.push_back(segL.prod(l, r).hash == segR.prod(n - r, n - l).hash);
        }
    }
    for (bool v : ans) output(v ? "Yes" : "No");
}
