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
    ll x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> even, odd, ansY, ansX;
    REP(i, n) {
        if (i % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }
    if (n <= 3) {
        even.push_back(0);
        even.push_back(0);
        odd.push_back(0);
        odd.push_back(0);
    }
    bool is_ok_y = false, is_ok_x = false;
    {
        vector<int> b1, b2;
        REP(i, even.size()) {
            if (i % 2 == 0) {
                b1.push_back(even[i]);
            } else {
                b2.push_back(even[i]);
            }
        }
        vector<ll> c1, c2;
        REP(bit, 1 << b1.size()) {
            ll sum = 0;
            REP(i, b1.size()) {
                if (bit & (1 << i)) {
                    sum += b1[i];
                } else {
                    sum -= b1[i];
                }
            }
            c1.push_back(sum);
        }
        REP(bit, 1 << b2.size()) {
            ll sum = 0;
            REP(i, b2.size()) {
                if (bit & (1 << i)) {
                    sum += b2[i];
                } else {
                    sum -= b2[i];
                }
            }
            c2.push_back(sum);
        }
        sort(ALL(c2));
        REP(i, c1.size()) {
            auto it = lower_bound(ALL(c2), y - c1[i]);
            if (it == c2.end()) continue;
            if (*it == y - c1[i]) {
                vector<ll> d1, d2;
                is_ok_y = true;
                REP(j, b1.size()) {
                    if (i & (1 << j)) {
                        d1.push_back(b1[j]);
                    } else {
                        d1.push_back(-b1[j]);
                    }
                }
                int k = it - c2.begin();
                REP(j, b2.size()) {
                    if (k & (1 << j)) {
                        d2.push_back(b2[j]);
                    } else {
                        d2.push_back(-b2[j]);
                    }
                }
                int len = max(d1.size(), d2.size());
                REP(j, len) {
                    ansY.push_back(d1[j]);
                    if (j < d2.size()) ansY.push_back(d2[j]);
                }
                break;
            }
        }
    }
    {
        vector<int> b1, b2;
        REP(i, odd.size()) {
            if (i % 2 == 0) {
                b1.push_back(odd[i]);
            } else {
                b2.push_back(odd[i]);
            }
        }
        vector<ll> c1, c2;
        REP(bit, 1 << b1.size()) {
            ll sum = 0;
            REP(i, b1.size()) {
                if (bit & (1 << i)) {
                    sum += b1[i];
                } else {
                    sum -= b1[i];
                }
            }
            c1.push_back(sum);
        }
        REP(bit, 1 << b2.size()) {
            ll sum = 0;
            REP(i, b2.size()) {
                if (bit & (1 << i)) {
                    sum += b2[i];
                } else {
                    sum -= b2[i];
                }
            }
            c2.push_back(sum);
        }
        sort(ALL(c2));
        REP(i, c1.size()) {
            auto it = lower_bound(ALL(c2), x - c1[i]);
            if (it == c2.end()) continue;
            if (*it == x - c1[i]) {
                vector<ll> d1, d2;
                is_ok_x = true;
                REP(j, b1.size()) {
                    if (i & (1 << j)) {
                        d1.push_back(b1[j]);
                    } else {
                        d1.push_back(-b1[j]);
                    }
                }
                int k = it - c2.begin();
                REP(j, b2.size()) {
                    if (k & (1 << j)) {
                        d2.push_back(b2[j]);
                    } else {
                        d2.push_back(-b2[j]);
                    }
                }
                int len = max(d1.size(), d2.size());
                REP(j, len) {
                    ansX.push_back(d1[j]);
                    if (j < d2.size()) ansX.push_back(d2[j]);
                }
                break;
            }
        }
    }
    if (is_ok_x && is_ok_y) {
        output("Yes");
        int len = max(ansX.size(), ansY.size());
        vector<int> ans;
        REP(i, len) {
            ans.push_back(ansY[i]);
            if (i < ansX.size()) ans.push_back(ansX[i]);
        }
        char now = 'R';
        string ans_str = "";
        REP(i, n) {
            if (i % 2 == 0) {
                if (ans[i] > 0) {
                    if (now == 'R') {
                        now = 'U';
                        ans_str += 'L';
                    } else {
                        now = 'U';
                        ans_str += 'R';
                    }
                } else {
                    if (now == 'R') {
                        now = 'D';
                        ans_str += 'R';
                    } else {
                        now = 'D';
                        ans_str += 'L';
                    }
                }
            } else {
                if (ans[i] > 0) {
                    if (now == 'U') {
                        now = 'R';
                        ans_str += 'R';
                    } else {
                        now = 'R';
                        ans_str += 'L';
                    }
                } else {
                    if (now == 'U') {
                        now = 'L';
                        ans_str += 'L';
                    } else {
                        now = 'L';
                        ans_str += 'R';
                    }
                }
            }
        }
        output(ans_str);
    } else {
        output("No");
    }
}
