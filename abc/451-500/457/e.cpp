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
int genRand(int min, int max) {
    static int flag;
    if (flag == 0) {
        srand((unsigned int)time(NULL));
        rand();
        flag = 1;
    }
    int ret = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
    return ret;
}

void test() {
    int n = 20;
    int m = 10;
    vector<int> l(m), r(m);
    REP(i, m) {
        int x = genRand(0, n - 1);
        l[i] = x;
        r[i] = genRand(x, n - 1);
    }
    vector<vector<pair<int, int>>> ltor(n), rtol(n);
    REP(i, m) {
        ltor[l[i]].emplace_back(r[i], i);
        rtol[r[i]].emplace_back(l[i], i);
    }
    REP(i, n) {
        sort(ALL(ltor[i]));
        sort(ALL(rtol[i]));
    }
    // メイン
    auto solve = [&](int s, int t) -> bool {
        if (ltor[s].size() == 0 || rtol[t].size() == 0) {
            return false;
        }
        int idx1 = upper_bound(ALL(ltor[s]), make_pair(t + 1, -1)) -
                   ltor[s].begin() - 1;
        int idx2 =
            lower_bound(ALL(rtol[t]), make_pair(s, -1)) - rtol[t].begin();
        if (idx1 < 0 || idx2 >= rtol[t].size()) {
            return false;
        }
        auto [right, i1] = ltor[s][idx1];
        auto [left, i2] = rtol[t][idx2];
        if (i1 != i2) {
            return left <= right || right + 1 == left;
        }
        // 同じ布を取ってきた場合
        assert(s == left && t == right);
        return idx1 - 1 >= 0 || idx2 + 1 < rtol[t].size();
    };

    auto naive = [&](int s, int t) -> bool {
        REP(i, m) {
            REP(j, i + 1, m) {
                vector<bool> check(n, false);
                REP(k, n) {
                    if (l[i] <= k && k <= r[i]) {
                        check[k] = true;
                    }
                    if (l[j] <= k && k <= r[j]) {
                        check[k] = true;
                    }
                }
                bool is_ok = true;
                REP(k, n) {
                    if (s <= k && k <= t) {
                        if (!check[k]) {
                            is_ok = false;
                        }
                    } else {
                        if (check[k]) {
                            is_ok = false;
                        }
                    }
                }
                if (is_ok) return true;
            }
        }
        return false;
    };

    int q = 10;
    REP(i, q) {
        int x = genRand(0, n - 1);
        int s = x;
        int t = genRand(x, n - 1);
        bool solveAns = solve(s, t);
        bool naiveAns = naive(s, t);
        if (solveAns != naiveAns) {
            output(solveAns ? "solve:true" : "solve:false");
            output(naiveAns ? "naive:true" : "naive:false");
            output(l);
            output(r);
            output(s, t);
            return;
        }
    }
}

int main() {
    test();
    return 0;

    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    REP(i, m) cin >> l[i] >> r[i], --l[i], --r[i];
    vector<vector<pair<int, int>>> ltor(n), rtol(n);
    REP(i, m) {
        ltor[l[i]].emplace_back(r[i], i);
        rtol[r[i]].emplace_back(l[i], i);
    }
    REP(i, n) {
        sort(ALL(ltor[i]));
        sort(ALL(rtol[i]));
    }
    // メイン
    auto solve = [&](int s, int t) -> bool {
        if (ltor[s].size() == 0 || rtol[t].size() == 0) {
            return false;
        }
        int idx1 = upper_bound(ALL(ltor[s]), make_pair(t + 1, -1)) -
                   ltor[s].begin() - 1;
        int idx2 =
            lower_bound(ALL(rtol[t]), make_pair(s, -1)) - rtol[t].begin();
        if (idx1 < 0 || idx2 >= rtol[t].size()) {
            return false;
        }
        auto [right, i1] = ltor[s][idx1];
        auto [left, i2] = rtol[t][idx2];
        if (i1 != i2) {
            return left <= right || right + 1 == left;
        }
        // 同じ布を取ってきた場合
        assert(s == left && t == right);
        return idx1 - 1 >= 0 || idx2 + 1 < rtol[t].size();
    };

    auto naive = [&](int s, int t) -> bool {
        REP(i, n) {
            REP(j, i + 1, n) {
                vector<bool> check(n, false);
                REP(k, n) {
                    if (l[i] <= k && k <= r[i]) {
                        check[k] = true;
                    }
                    if (l[j] <= k && k <= r[j]) {
                        check[k] = true;
                    }
                }
                bool is_ok = true;
                REP(k, n) {
                    if (s <= k && k <= t) {
                        if (!check[k]) {
                            is_ok = false;
                        }
                    } else {
                        if (check[k]) {
                            is_ok = false;
                        }
                    }
                }
                if (is_ok) return true;
            }
        }
        return false;
    };

    int q;
    cin >> q;
    vector<bool> ans(q);
    REP(i, q) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        ans[i] = solve(s, t);
    }
    REP(i, q) YesNo(ans[i]);
}
