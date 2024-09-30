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
template <class T> struct Zobrist_Hash {
   public:
    Zobrist_Hash(vector<T> a) : n(a.size()) {
        // ハッシュ割り当て
        static unordered_map<T, long long> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.find(a[i]) == mp.end()) {
                mp[a[i]] = get_rand_range(1, mod - 1);
            }
        }
        // 累積和
        tot.resize(n + 1);
        tot[0] = 0;
        for (int i = 0; i < n; ++i) {
            tot[i + 1] = (tot[i] + mp[a[i]]) % mod;
        }
    }

    // [l, r)
    long long hash(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return (tot[r] - tot[l] + mod) % mod;
    }

   private:
    static const long long mod = (1LL << 61) - 1;
    int n;
    vector<long long> tot;

    long long get_rand_range(long long min_val, long long max_val) {
        static mt19937_64 mt64(0);
        uniform_int_distribution<uint64_t> get_rand_uni_int(min_val, max_val);
        return get_rand_uni_int(mt64);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    Zobrist_Hash hashA(a), hashB(b);
    vector<bool> ans(q);
    REP(i, q) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        --l, --L;
        ans[i] = hashA.hash(l, r) == hashB.hash(L, R);
    }
    REP(i, q) { YesNo(ans[i]); }
}
