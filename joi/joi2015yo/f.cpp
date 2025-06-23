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
ll op(ll a, ll b) { return max(a, b); }

ll e() { return -INF64; }

int main() {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    int h = n / 2;
    vector<pair<ll, ll>> axy;
    auto dfsA = [&](auto &dfs, int pos = 0, ll sumAX = 0, ll sumAY = 0,
                    ll sumBX = 0, ll sumBY = 0) -> void {
        if (pos == h) {
            axy.emplace_back(sumBX - sumAX, sumBY - sumAY);
            return;
        }
        // Anna
        sumAX += x[pos];
        sumAY += y[pos];
        dfs(dfs, pos + 1, sumAX, sumAY, sumBX, sumBY);
        sumAX -= x[pos];
        sumAY -= y[pos];
        // Bruno
        sumBX += x[pos];
        sumBY += y[pos];
        dfs(dfs, pos + 1, sumAX, sumAY, sumBX, sumBY);
        sumBX -= x[pos];
        sumBY -= y[pos];
        // other
        dfs(dfs, pos + 1, sumAX, sumAY, sumBX, sumBY);
    };
    dfsA(dfsA);
    vector<pair<ll, ll>> bxy;
    auto dfsB = [&](auto &dfs, int pos, ll sumAX = 0, ll sumAY = 0,
                    ll sumBX = 0, ll sumBY = 0) -> void {
        if (pos == n) {
            bxy.emplace_back(sumBX - sumAX, sumBY - sumAY);
            return;
        }
        // Anna
        sumAX += x[pos];
        sumAY += y[pos];
        dfs(dfs, pos + 1, sumAX, sumAY, sumBX, sumBY);
        sumAX -= x[pos];
        sumAY -= y[pos];
        // Bruno
        sumBX += x[pos];
        sumBY += y[pos];
        dfs(dfs, pos + 1, sumAX, sumAY, sumBX, sumBY);
        sumBX -= x[pos];
        sumBY -= y[pos];
        // other
        dfs(dfs, pos + 1, sumAX, sumAY, sumBX, sumBY);
    };
    dfsB(dfsB, h);
    // Xが価値、Yが貴重度
    vector<ll> bx;
    sort(ALL(bxy));
    segtree<ll, op, e> seg(bxy.size());
    int cnt = 0;
    for (auto [_x, _y] : bxy) {
        bx.push_back(_x);
        seg.set(cnt, _y);
        ++cnt;
    }
    ll ans = 0;
    for (auto [_x, _y] : axy) {
        int l = lower_bound(ALL(bx), -d - _x) - bx.begin();
        int r = upper_bound(ALL(bx), d - _x) - bx.begin();
        chmax(ans, _y + seg.prod(l, r));
    }
    output(ans);
}
