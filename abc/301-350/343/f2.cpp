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
    int max1;
    int max2;
    int max1_cnt;
    int max2_cnt;
};

S op(S a, S b) {
    set<int> st;
    st.insert(a.max1);
    st.insert(a.max2);
    st.insert(b.max1);
    st.insert(b.max2);
    if (st.size() == 1) {
        auto max1 = st.end();
        --max1;
        return {*max1, -1, a.max1_cnt + b.max1_cnt, 0};
    } else {
        auto max1 = st.end();
        --max1;
        auto max2 = st.end();
        --max2;
        --max2;
        int max1_cnt = 0, max2_cnt = 0;
        // 最大値
        if (*max1 == a.max1) {
            max1_cnt += a.max1_cnt;
        }
        if (*max1 == b.max1) {
            max1_cnt += b.max1_cnt;
        }
        // 2番目の最大値
        if (*max2 == a.max1) {
            max2_cnt += a.max1_cnt;
        }
        if (*max2 == a.max2) {
            max2_cnt += a.max2_cnt;
        }
        if (*max2 == b.max1) {
            max2_cnt += b.max1_cnt;
        }
        if (*max2 == b.max2) {
            max2_cnt += b.max2_cnt;
        }
        return {*max1, *max2, max1_cnt, max2_cnt};
    }
}

S e() { return {-1, -1, 0, 0}; }

int main() {
    int n, q;
    cin >> n >> q;
    segtree<S, op, e> seg(n);
    REP(i, n) {
        int a;
        cin >> a;
        seg.set(i, {a, -1, 1, 0});
    }
    vector<int> ans;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            seg.set(p, {x, -1, 1, 0});
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            auto s = seg.prod(l, r);
            ans.push_back(s.max2_cnt);
        }
    }
    REP(i, ans.size()) output(ans[i]);
}
