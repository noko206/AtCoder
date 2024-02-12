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
/**
 * @brief Dynamic-Li-Chao-Tree
 * @docs docs/dynamic-li-chao-tree.md
 */
template <typename T, T x_low, T x_high, T id> struct DynamicLiChaoTree {
    struct Line {
        T a, b;

        Line(T a, T b) : a(a), b(b) {}

        inline T get(T x) const { return a * x + b; }
    };

    struct Node {
        Line x;
        Node *l, *r;

        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}
    };

    Node *root;

    DynamicLiChaoTree() : root{nullptr} {}

    Node *add_line(Node *t, Line &x, const T &l, const T &r, const T &x_l,
                   const T &x_r) {
        if (!t) return new Node(x);

        T t_l = t->x.get(l), t_r = t->x.get(r);

        if (t_l <= x_l && t_r <= x_r) {
            return t;
        } else if (t_l >= x_l && t_r >= x_r) {
            t->x = x;
            return t;
        } else {
            T m = (l + r) / 2;
            if (m == r) --m;
            T t_m = t->x.get(m), x_m = x.get(m);
            if (t_m > x_m) {
                swap(t->x, x);
                if (x_l >= t_l)
                    t->l = add_line(t->l, x, l, m, t_l, t_m);
                else
                    t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);
            } else {
                if (t_l >= x_l)
                    t->l = add_line(t->l, x, l, m, x_l, x_m);
                else
                    t->r = add_line(t->r, x, m + 1, r, x_m + x.a, x_r);
            }
            return t;
        }
    }

    void add_line(const T &a, const T &b) {
        Line x(a, b);
        root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
    }

    Node *add_segment(Node *t, Line &x, const T &a, const T &b, const T &l,
                      const T &r, const T &x_l, const T &x_r) {
        if (r < a || b < l) return t;
        if (a <= l && r <= b) {
            Line y{x};
            return add_line(t, y, l, r, x_l, x_r);
        }
        if (t) {
            T t_l = t->x.get(l), t_r = t->x.get(r);
            if (t_l <= x_l && t_r <= x_r) return t;
        } else {
            t = new Node(Line(0, id));
        }
        T m = (l + r) / 2;
        if (m == r) --m;
        T x_m = x.get(m);
        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);
        t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);
        return t;
    }

    void add_segment(const T &l, const T &r, const T &a, const T &b) {
        Line x(a, b);
        root = add_segment(root, x, l, r - 1, x_low, x_high, x.get(x_low),
                           x.get(x_high));
    }

    T query(const Node *t, const T &l, const T &r, const T &x) const {
        if (!t) return id;
        if (l == r) return t->x.get(x);
        T m = (l + r) / 2;
        if (m == r) --m;
        if (x <= m)
            return min(t->x.get(x), query(t->l, l, m, x));
        else
            return min(t->x.get(x), query(t->r, m + 1, r, x));
    }

    T query(const T &x) const { return query(root, x_low, x_high, x); }
};

int main() {
    int n;
    ll c;
    cin >> n >> c;
    vector<int> h(n);
    REP(i, n) cin >> h[i]; 
    DynamicLiChaoTree<ll, -INF32, INF32, INF64> cht;
    vector<ll> dp(n, INF64);
    dp[0] = 0;
    REP(i, n) {
        chmin(dp[i], cht.query(h[i]) + (ll)h[i] * h[i] + c);
        cht.add_line(-2 * h[i], dp[i] + (ll)h[i] * h[i]);
    }
    output(dp[n - 1]);
}
