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
    int n, m;
    cin >> n >> m;
    vector to(n, vector<bool>(n, false));
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a][b] = true;
        to[b][a] = true;
    }
    vector<int> bits;
    REP(bit, 1 << n) {
        if (bit & (1 << (n - 1))) continue;
        int cnt = 0;
        bool is_ok = true;
        REP(i, n) {
            if (bit & (1 << i)) {
                ++cnt;
            } else {
                if (cnt <= 1) {
                    is_ok = false;
                }
                cnt = 0;
            }
        }
        if (is_ok) {
            bits.push_back(bit);
        }
    }
    vector<int> p(n);
    REP(i, n) p[i] = i;
    int kotae = INF32;
    do {
        for (int bit : bits) {
            vector<int> v;  // 毎回使いまわし
            int ans = 0;
            map<pair<int, int>, bool> mp;  // 全体で使いまわし
            REP(i, n) {
                if (bit & (1 << i)) {
                    v.push_back(p[i]);
                    continue;
                }
                v.push_back(p[i]);
                int len = v.size();
                REP(j, len) {
                    int prev = (j - 1 + len) % len;
                    int next = (j + 1) % len;
                    REP(k, n) {
                        if (k == v[next] || k == v[prev]) continue;
                        if (to[v[j]][k] && mp.find({v[j], k}) == mp.end()) {
                            ++ans;
                            mp[{v[j], k}] = true;
                            mp[{k, v[j]}] = true;
                        }
                    }
                    if (!to[v[j]][v[next]]) {
                        ++ans;
                    }
                }
                v.clear();
            }
            // output(p);
            // output(ans);
            chmin(kotae, ans);
        }
    } while (next_permutation(ALL(p)));
    output(kotae);
}
