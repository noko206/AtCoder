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
int main() {
    int n;
    cin >> n;
    fenwick_tree<ll> a(n);
    map<int, int> b;
    REP(i, n) {
        int x;
        cin >> x;
        a.add(i, x);
    }
    REP(i, n) {
        int x;
        cin >> x;
        if (x >= 2) {
            b[i] = x;
        }
    }
    int q;
    cin >> q;
    vector<ll> ans;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            a.add(i, x - a.sum(i, i + 1));
        } else if (t == 2) {
            int i, x;
            cin >> i >> x;
            --i;
            if (b.find(i) != b.end()) {
                b.erase(i);
            }
            if (x >= 2) {
                b[i] = x;
            }
        } else {
            int l, r;
            cin >> l >> r;
            ll v = a.sum(l - 1, l);
            while (l != r) {
                auto it = b.lower_bound(l);
                if (it == b.end()) {
                    v += a.sum(l, r);
                    break;
                }
                auto [next_l, x] = *it;
                if (next_l >= r) {
                    v += a.sum(l, r);
                    break;
                }
                v += a.sum(l, next_l);
                v = max(v + a.sum(next_l, next_l + 1), v * x);
                l = next_l + 1;
            }
            ans.push_back(v);
        }
    }
    output(ans);
}
