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
int n;
int a[50];

struct S {
    ll value;
    int max;
    int next;
    vector<int> cnt;
    int id;
};

S op(S x, S y) {
    if (y.next == n) {
        return x;
    }
    if (x.next == n) {
        return y;
    }
    if (x.value - a[x.max] + a[x.next] >= y.value - a[y.max] + a[y.next]) {
        return x;
    } else {
        return y;
    }
}

S e() {
    S x;
    x.value = 0;
    x.max = -1;
    x.next = n;
    vector<int> cnt(n, 0);
    x.cnt = cnt;
    x.id = -1;
    return x;
}

int main() {
    int k, x;
    cin >> n >> k >> x;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    ll sum = (ll)a[n - 1] * k;
    segtree<S, op, e> seg(100000);
    {
        S s;
        s.value = sum;
        s.max = n - 1;
        s.next = 1;
        vector<int> cnt(n, 0);
        cnt[0] = k;
        s.cnt = cnt;
        s.id = 0;
        seg.set(0, s);
    }
    REP(i, x - 1) {
        auto s = seg.prod(0, i + 1);
        auto t = s;
        // s
        {
            ++s.next;
        }
        // t
        {
            t.value += a[s.next] - a[s.max];
            --t.cnt[s.max];
            ++t.cnt[s.next];
            while (true) {
                if (t.cnt[t.max] != 0) {
                    break;
                }
                --t.max;
                t.next = t.max + 1;
            }
            t.id = i + 1;
        }
        seg.set(s.id, s);
        seg.set(t.id, t);
    }
    vector<ll> ans(x);
    REP(i, x) { ans[i] = seg.get(i).value; }
    REP(i, x) output(ans[i]);
}
