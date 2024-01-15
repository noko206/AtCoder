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
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
template <typename T>
pair<unordered_map<T, int>, vector<T>> compress(const vector<T> &a) {
    auto decomp = a;
    sort(decomp.begin(), decomp.end());
    decomp.erase(unique(decomp.begin(), decomp.end()), decomp.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)decomp.size(); ++i) {
        comp[decomp[i]] = i;
    }
    return {comp, decomp};
}

int op(int a, int b) { return min(a, b); }

int e() { return INF32; }

int main() {
    int n;
    cin >> n;
    vector a(n, vector<int>(3));
    REP(i, n) REP(j, 3) cin >> a[i][j];
    REP(i, n) sort(ALL(a[i]));
    sort(ALL(a));
    vector<int> b(n);
    REP(i, n) b[i] = a[i][1];
    auto [comp, decomp] = compress(b);
    segtree<int, op, e> seg((int)comp.size());
    bool same = false;
    vector<pair<int, int>> p;
    REP(i, n) {
        int mn = seg.prod(0, comp[a[i][1]]);
        if (mn < a[i][2]) {
            cout << "Yes" << endl;
            return 0;
        }
        if (i == n - 1) break;
        p.push_back({comp[a[i][1]], a[i][2]});
        if (a[i][0] != a[i + 1][0]) {
            for (auto [x, y] : p) {
                if (seg.get(x) > y) {
                    seg.set(x, y);
                }
            }
            p.clear();
        }
    }
    cout << "No" << endl;
}
