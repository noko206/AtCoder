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
struct RollingHash {
   public:
    RollingHash(const string &s, int base = 100, int mod = 998244353)
        : base(base), mod(mod), hash(s.length()) {
        mint::set_mod(mod);
        build(s);
    }

    // [l, r)
    int query(int l, int r) {
        mint ans = hash[r] - (hash[l] * pow_mod(base, r - l, mod));
        return ans.val();
    }

   private:
    using mint = modint;
    int base;
    int mod;
    vector<mint> hash;

    void build(const string &s) {
        int n = s.length();
        hash[0] = 0;
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = hash[i] * base + s[i];
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s;
    t = s;
    reverse(ALL(t));
    RollingHash hash_s(s);
    RollingHash hash_t(t);
    vector<bool> ans(q);
    REP(i, q) {
        int l, r;
        cin >> l >> r;
        --l;
        int hash1 = hash_s.query(l, r);
        int hash2 = hash_t.query(n - r, n - l);
        ans[i] = hash1 == hash2;
    }
    REP(i, q) YesNo(ans[i]);
}
