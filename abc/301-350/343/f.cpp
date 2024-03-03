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
};

S op(S a, S b) {
    vector<int> v(4);
    v[0] = a.max1;
    v[1] = a.max2;
    v[2] = b.max1;
    v[3] = b.max2;
    sort(ALL(v));
    return {v[3], v[2]};
}

S e() { return {-1, -1}; }

template <typename T> unordered_map<T, int> compress(vector<T> &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)a.size(); ++i) {
        comp[a[i]] = i;
    }
    return comp;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> za;
    vector<int> a(n);
    REP(i, n) cin >> a[i], za.push_back(a[i]);
    vector<tuple<int, int, int>> query(q);
    REP(i, q) {
        int x, y, z;
        cin >> x >> y >> z;
        qurey[i] = {x, y, z};
        if (x == 1) za.push_back(z);
    }
    // 座圧
    auto comp = compress(za);
    REP(i, n) a[i] = comp[a[i]];
    REP(i, q) {
        auto [x, y, z] = query[i];
        query[i] = {x, y, comp[z]};
    }
    // 個数カウント用セット
    vector<set<int>> st(comp.size());
    REP(i, n) st[a[i]].insert(i);
    // さらに座圧用前処理
    vector<int> zatsu(n);
    REP(i, n) zatsu[a[i]].push_back(i);
    {
        segtree<S, op, e> seg(a);
        for (auto [t, x, y]) {
            if (t == 1) {
                --x;
                int now = seg.get(x);
                st[now].erase(x);
                seg.set(x, y);
                st[y].insert(x);
                zatsu[y].push_back(x);
            } else {
                --x;
                auto s = seg.prod(x, y);
                if (x.max2 == -1) {
                    //
                } else {
                    zatsu[y].push_back(x);
                }
            }
        }
    }
    vector<unordered_map<int, int>> comp2(n);
    REP(i, n) comp2[i] = compress(zatsu[i]);
    // メイン処理
    vector<int> ans;
    {
        segtree<S, op, e> seg(a);
        for (auto [t, x, y]) {
            if (t == 1) {
                --x;
                int now = seg.get(x);
                st[now].erase(x);
                seg.set(x, y);
                st[y].insert(x);
                zatsu[y].push_back(x);
            } else {
                --x;
                auto s = seg.prod(x, y);
                if (x.max2 == -1) {
                    ans.push_back(0);
                } else {
                    zatsu[y].push_back(x);
                }
            }
        }
    }
    output(ans);
}
