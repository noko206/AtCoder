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
struct S {
    int cnt;
    ll sum;
};

S op(S a, S b) {
    S ans;
    ans.cnt = a.cnt + b.cnt;
    ans.sum = a.sum + b.sum;
    return ans;
}

S e() {
    S ans;
    ans.cnt = 0;
    ans.sum = 0;
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    segtree<S, op, e> seg(500005);
    REP(i, n) {
        S x = seg.get(a[i]);
        x.cnt += 1;
        x.sum += a[i];
        seg.set(a[i], x);
    }
    vector<ll> ans;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            --x;
            S pre = seg.get(a[x]);
            pre.cnt -= 1;
            pre.sum -= a[x];
            seg.set(a[x], pre);
            a[x] = y;
            S next = seg.get(y);
            next.cnt += 1;
            next.sum += y;
            seg.set(y, next);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            if (r < l) {
                ans.push_back((ll)n * l);
                continue;
            }
            S left = seg.prod(0, l);
            S middle = seg.prod(l, r);
            S right = seg.prod(r, 500005);
            ll sum = 0;
            sum += (ll)left.cnt * l;
            sum += middle.sum;
            sum += (ll)right.cnt * r;
            ans.push_back(sum);
        }
    }
    REP(i, ans.size()) output(ans[i]);
}
