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
using P = pair<ll, ll>;

int solve(int n, vector<int> x, vector<int> y) {
    vector<P> left, right;
    REP(i, n) {
        bool is_left = false;
        if (x[i] == 0) {
            assert(y[i] != 0);  // 制約より
            if (y[i] > 0) {     // 上にいるやつを左側にする
                is_left = true;
            }
        } else if (x[i] < 0) {
            is_left = true;
        }
        if (is_left) {
            left.emplace_back(x[i], y[i]);
        } else {
            right.emplace_back(x[i], y[i]);
        }
    }
    auto comp = [](P a, P b) -> bool {
        return a.second * b.first < a.first * b.second;
    };
    sort(ALL(left), comp);
    sort(ALL(right), comp);
    int ok = 0;
    int ng = n + 1;
    auto f = [&](const vector<P>& v, ll x, ll y) -> int {
        int ok = -1, ng = v.size();
        while (ng - ok != 1) {
            int mid = (ok + ng) / 2;
            if (y * v[mid].first <= x * v[mid].second) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    };
    int ans = 0;
    REP(_, 2) {
        int cntL = left.size(), cntR = right.size();
        chmax(ans, max(cntL, cntR));
        int pre = -1;
        REP(i, left.size()) {
            int pos = f(right, left[i].first, left[i].second);
            --cntL;             // 減った分
            cntL += pos - pre;  // 増えた分
            ++cntR;
            cntR -= pos - pre;
            assert(cntL + cntR == n);
            assert(cntL >= 0 && cntR >= 0);
            pre = pos;
            chmax(ans, max(cntL, cntR));
        }
        if (_ == 0) swap(left, right);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        REP(i, n) cin >> x[i] >> y[i];
        ans.push_back(solve(n, x, y));
    }
    for (int x : ans) {
        output(x);
    }
}
