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
// {dr, dc}
pair<int, int> f(char c) {
    if (c == 'U') {
        return {-1, 0};
    } else if (c == 'D') {
        return {1, 0};
    } else if (c == 'L') {
        return {0, -1};
    } else {
        return {0, 1};
    }
}

int main() {
    ll rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;
    ll n;
    int m, l;
    cin >> n >> m >> l;
    vector<char> s(m), t(l);
    vector<ll> a(m), b(l);
    REP(i, m) cin >> s[i] >> a[i];
    REP(i, l) cin >> t[i] >> b[i];
    int posA = 0;
    int posB = 0;
    ll ans = 0;
    while (posA < m && posB < l) {
        ll cnt = min(a[posA], b[posB]);
        if (s[posA] == t[posB]) {
            if (rt == ra && ct == ca) {
                ans += cnt;
            }
        } else {
            if (s[posA] == 'U') {
                if (t[posB] == 'D') {
                    ll tmp = rt - ra;
                    if (tmp % 2 == 0 && ct == ca) {
                        tmp /= 2;
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'L') {
                    ll tmp = rt - ra;
                    if (tmp == ca - ct) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'R') {
                    ll tmp = rt - ra;
                    if (tmp == ct - ca) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                }
            } else if (s[posA] == 'D') {
                if (t[posB] == 'U') {
                    ll tmp = ra - rt;
                    if (tmp % 2 == 0 && ct == ca) {
                        tmp /= 2;
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'L') {
                    ll tmp = ra - rt;
                    if (tmp == ca - ct) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'R') {
                    ll tmp = ra - rt;
                    if (tmp == ct - ca) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                }
            } else if (s[posA] == 'L') {
                if (t[posB] == 'U') {
                    ll tmp = ra - rt;
                    if (tmp == ct - ca) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'D') {
                    ll tmp = rt - ra;
                    if (tmp == ct - ca) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'R') {
                    ll tmp = ct - ca;
                    if (tmp % 2 == 0 && rt == ra) {
                        tmp /= 2;
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                }
            } else {
                if (t[posB] == 'U') {
                    ll tmp = ra - rt;
                    if (tmp == ca - ct) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'D') {
                    ll tmp = rt - ra;
                    if (tmp == ca - ct) {
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                } else if (t[posB] == 'L') {
                    ll tmp = ca - ct;
                    if (tmp % 2 == 0 && rt == ra) {
                        tmp /= 2;
                        if (tmp <= cnt && tmp > 0) {
                            ++ans;
                        }
                    }
                }
            }
        }
        // 移動
        {
            auto [rd, cd] = f(s[posA]);
            rt += rd * cnt;
            ct += cd * cnt;
        }
        {
            auto [rd, cd] = f(t[posB]);
            ra += rd * cnt;
            ca += cd * cnt;
        }
        // 後処理
        a[posA] -= cnt;
        b[posB] -= cnt;
        if (a[posA] == 0) {
            ++posA;
        }
        if (b[posB] == 0) {
            ++posB;
        }
    }
    output(ans);
}
