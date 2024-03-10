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
    int left;
    int right;
    int val;
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<S> lis;
    map<int, int> to;
    lis.push_back({-1, 1, -1});  // 番兵を追加
    to[-1] = 0;
    REP(i, n) {
        lis.push_back({i, i + 2, a[i]});
        to[a[i]] = i + 1;
    }
    lis.push_back({n, n + 2, INF32});  // 番兵を追加
    to[INF32] = n + 1;
    int q;
    cin >> q;
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            int posX = to[x];
            int posY = lis.size();
            int posZ = lis[posX].right;
            // yを書き換え
            lis.push_back({posX, posZ, y});
            to[y] = posY;
            // xを書き換え
            lis[posX].right = lis.size() - 1;
            // xの右隣を書き換え(z)
            lis[posZ].left = lis.size() - 1;
        } else {
            int x;
            cin >> x;
            int posX = to[x];
            int posY = lis[posX].left;
            int posZ = lis[posX].right;
            // xの左隣を書き換え(y)
            lis[posY].right = posZ;
            // xの右隣を書き換え(z)
            lis[posZ].left = posY;
        }
    }
    int pos = lis[0].right;
    vector<int> ans;
    while (lis[pos].val != INF32) {
        ans.push_back(lis[pos].val);
        pos = lis[pos].right;
    }
    output(ans);
}
