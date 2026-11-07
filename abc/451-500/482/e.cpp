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
    vector<vector<int>> to(n);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<int> c(n);
    REP(i, n) cin >> c[i], --c[i];
    vector<int> maxDist(2, 0), maxV(2, -1), tmp;
    int center, centerL, centerR, last, len;
    auto dfs = [&](auto& dfs, int v, int flg, int p = -1) -> void {
        tmp.push_back(v);
        if (chmax(maxDist[flg], (int)tmp.size() - 1)) {
            maxV[flg] = v;
            if (flg) {
                if (tmp.size() % 2 == 0) {
                    last = 0;
                    len = tmp.size() - 1;  // 直径の長さ
                    centerL = tmp[tmp.size() / 2 - 1];
                    centerR = tmp[tmp.size() / 2];
                } else {
                    last = 1;
                    len = tmp.size() - 1;  // 直径の長さ
                    center = tmp[tmp.size() / 2];
                }
            }
        }
        for (int u : to[v]) {
            if (u == p) continue;
            dfs(dfs, u, flg, v);
        }
        tmp.pop_back();
    };
    dfs(dfs, 0, 0);
    dfs(dfs, maxV[0], 1);
    ll ans = 0;
    if (last) {
        // 真ん中が1個
        vector<int> dist(n, 0);
        auto dfs2 = [&](auto& dfs2, int v, int p = -1) -> void {
            for (int u : to[v]) {
                if (u == p) continue;
                dist[u] = dist[v] + 1;
                dfs2(dfs2, u, v);
            }
        };
        dfs2(dfs2, center);
        vector<map<int, int>> dc2c(n);
        REP(i, n) dc2c[dist[i]][c[i]]++;
        // REP(i, n) {
        //     if (dist[i] != len / 2) continue;
        //     dc2c[len / 2][c[i]]--;  // 自身を減らす
        //     ans += dc2c[len / 2][c[i]];
        // }
        set<int> st;
        REP(i, n) st.insert(c[i]);
        for (int v : st) {
            ans += (ll)dc2c[len / 2][v] * (dc2c[len / 2][v] - 1) / 2;
        }
    } else {
        // 真ん中が2個
        vector<int> distL(n, 0), distR(n, 0);
        vector<bool> isL(n);
        // output(centerL + 1, centerR + 1);
        auto dfsL = [&](auto& dfsL, int v, int p = -1) -> void {
            isL[v] = true;
            for (int u : to[v]) {
                if (u == p) continue;
                if (u == centerR) continue;
                distL[u] = distL[v] + 1;
                dfsL(dfsL, u, v);
            }
        };
        auto dfsR = [&](auto& dfsR, int v, int p = -1) -> void {
            isL[v] = false;
            for (int u : to[v]) {
                if (u == p) continue;
                if (u == centerL) continue;
                distR[u] = distR[v] + 1;
                dfsR(dfsR, u, v);
            }
        };
        dfsL(dfsL, centerL);
        dfsR(dfsR, centerR);
        vector<map<int, int>> dc2cL(n), dc2cR(n);
        REP(i, n) {
            if (isL[i]) {
                dc2cL[distL[i]][c[i]]++;
            } else {
                dc2cR[distR[i]][c[i]]++;
            }
        }
        REP(i, n) {
            if (isL[i]) {
                dc2cL[distL[i]][c[i]]--;  // 自身を減らす
                ans += dc2cR[len - distL[i] - 1][c[i]];
            } else {
                dc2cR[distR[i]][c[i]]--;  // 自身を減らす
                ans += dc2cL[len - distR[i] - 1][c[i]];
            }
        }
    }
    output(ans);
}
