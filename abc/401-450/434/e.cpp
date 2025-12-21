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
    vector<int> x(n), r(n);
    REP(i, n) cin >> x[i] >> r[i];
    multiset<pair<int, int>> st;
    map<int, int> cnt;
    vector<int> val(n, -2000000001);
    map<int, bool> decided;
    REP(i, n) {
        st.insert({x[i] - r[i], i});
        st.insert({x[i] + r[i], i});
        ++cnt[x[i] - r[i]];
        ++cnt[x[i] + r[i]];
    }
    for (auto [pos, i] : st) {
        if (val[i] != -2000000001) continue;
        int a = x[i] - r[i], b = x[i] + r[i];
        if (cnt[a] == 1 && decided.find(a) == decided.end()) {
            val[i] = a;
            --cnt[a];
            --cnt[b];
            decided[a] = true;
            continue;
        }
        if (cnt[b] == 1 && decided.find(b) == decided.end()) {
            val[i] = b;
            --cnt[a];
            --cnt[b];
            decided[b] = true;
            continue;
        }
        if (decided.find(a) == decided.end()) {
            val[i] = a;
            --cnt[a];
            --cnt[b];
            decided[a] = true;
            continue;
        }
        if (decided.find(pos) == decided.end()) {
            val[i] = pos;
            --cnt[a];
            --cnt[b];
            decided[pos] = true;
            continue;
        }
        if (decided.find(b) == decided.end()) {
            val[i] = b;
            --cnt[a];
            --cnt[b];
            decided[b] = true;
            continue;
        }
        val[i] = pos;
        --cnt[a];
        --cnt[b];
        decided[pos] = true;
    }
    set<int> st2;
    REP(i, n) st2.insert(val[i]);
    output(st2.size());
}
