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
using mat = vector<vector<ll>>;

mat mul(mat l, mat r) {
    mat ans(l.size());
    REP(li, l.size()) {
        REP(rj, r[0].size()) {
            ll sum = 0;
            REP(k, l[li].size()) { sum += l[li][k] * r[k][rj]; }
            ans[li].push_back(sum);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    int m;
    cin >> m;
    vector tot(m + 1, vector(3, vector<ll>(3)));
    tot[0][0] = {1, 0, 0};
    tot[0][1] = {0, 1, 0};
    tot[0][2] = {0, 0, 1};
    vector one(3, vector<ll>(3));
    one[0] = {0, 1, 0};
    one[1] = {-1, 0, 0};
    one[2] = {0, 0, 1};
    vector two(3, vector<ll>(3));
    two[0] = {0, -1, 0};
    two[1] = {1, 0, 0};
    two[2] = {0, 0, 1};
    vector three(3, vector<ll>(3));
    three[0] = {-1, 0, 2};
    three[1] = {0, 1, 0};
    three[2] = {0, 0, 1};
    vector four(3, vector<ll>(3));
    four[0] = {1, 0, 0};
    four[1] = {0, -1, 2};
    four[2] = {0, 0, 1};
    REP(i, m) {
        int t;
        cin >> t;
        if (t == 1) {
            tot[i + 1] = mul(one, tot[i]);
        } else if (t == 2) {
            tot[i + 1] = mul(two, tot[i]);
        } else if (t == 3) {
            int p;
            cin >> p;
            auto tmp = three;
            tmp[0][2] = 2 * p;
            tot[i + 1] = mul(tmp, tot[i]);
        } else {
            int p;
            cin >> p;
            auto tmp = four;
            tmp[1][2] = 2 * p;
            tot[i + 1] = mul(tmp, tot[i]);
        }
    }
    int q;
    cin >> q;
    vector<pair<ll, ll>> ans(q);
    REP(i, q) {
        int a, b;
        cin >> a >> b;
        --b;
        mat c(3);
        c[0].push_back(x[b]);
        c[1].push_back(y[b]);
        c[2].push_back(1);
        auto tmp = mul(tot[a], c);
        ans[i] = {tmp[0][0], tmp[1][0]};
    }
    for (auto [a, b] : ans) output(a, b);
}
