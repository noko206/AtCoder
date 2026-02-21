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
template <class T> vector<pair<T, int>> prime_factorize(T n) {
    vector<pair<T, int>> ans;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        T e = 0;
        while (n % i == 0) {
            ++e;
            n /= i;
        }
        ans.push_back({i, e});
    }
    if (n != 1) ans.push_back({n, 1});
    return ans;
}

template <typename T>
pair<unordered_map<T, int>, vector<T>> compress(const vector<T>& a) {
    auto decomp = a;
    sort(decomp.begin(), decomp.end());
    decomp.erase(unique(decomp.begin(), decomp.end()), decomp.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)decomp.size(); ++i) {
        comp[decomp[i]] = i;
    }
    return {comp, decomp};
}

int op(int a, int b) { return max(a, b); }

int e() { return 0; }

using mint = modint998244353;

vector<int> solve(int n, const vector<int>& a) {
    vector<vector<pair<int, int>>> pf(n);
    REP(i, n) pf[i] = prime_factorize(a[i]);
    vector<int> tmp;
    REP(i, n) {
        for (auto [x, _] : pf[i]) {
            tmp.push_back(x);
        }
    }
    auto [comp, decomp] = compress(tmp);
    int num = 0;
    for (auto x : decomp) {
        if (x <= 3162) num++;
    }
    vector seg(num, segtree<int, op, e>(n));
    map<int, int> cnt;
    map<pair<int, int>, bool> mp;
    REP(i, n) {
        for (auto [x, y] : pf[i]) {
            if (x <= 3162) {
                seg[comp[x]].set(i, y);
            } else {
                ++cnt[x];
                mp[{i, x}] = true;
            }
        }
    }
    mint sum = 1;
    REP(i, comp.size()) {
        if (decomp[i] <= 3162) {
            sum *= pow_mod(decomp[i], seg[i].all_prod(), 998244353);
        } else {
            sum *= decomp[i];
        }
    }
    vector<int> ans(n);
    REP(i, n) {
        for (auto [x, y] : pf[i]) {
            if (x <= 3162) {
                sum /= pow_mod(x, seg[comp[x]].all_prod(), 998244353);
                int l = seg[comp[x]].prod(0, i);
                int r = seg[comp[x]].prod(i + 1, n);
                sum *= pow_mod(x, max(l, r), 998244353);
            } else {
                if (mp.find({i, x}) == mp.end()) continue;
                if (cnt[x] != 1) continue;
                sum /= x;
            }
        }
        ans[i] = sum.val();
        for (auto [x, y] : pf[i]) {
            if (x <= 3162) {
                int l = seg[comp[x]].prod(0, i);
                int r = seg[comp[x]].prod(i + 1, n);
                sum /= pow_mod(x, max(l, r), 998244353);
                sum *= pow_mod(x, seg[comp[x]].all_prod(), 998244353);
            } else {
                if (mp.find({i, x}) == mp.end()) continue;
                if (cnt[x] != 1) continue;
                sum *= x;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    REP(i, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(j, n) cin >> a[j];
        output(solve(n, a));
    }
}
