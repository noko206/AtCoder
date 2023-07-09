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
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool f(vector<string> s) {
    bool is_ok = true;
    REP(i, 8) {
        REP(j, 8) {
            if (s[i][j] != 'Q') continue;
            REP(k, 1, 8) {
                REP(l, 8) {
                    int y = i + dy[l] * k;
                    int x = j + dx[l] * k;
                    if (y < 0 || x < 0 || y >= 8 || x >= 8) continue;
                    if (s[y][x] == 'Q') is_ok = false;
                }
            }
        }
    }
    return is_ok;
}

void test() {
    vector<string> s(8);
    REP(i, 8) cin >> s[i];
    if (f(s)) output("ok");
}

int main() {
    int n;
    cin >> n;
    vector<int> r(n), c(n);
    REP(i, n) cin >> r[i] >> c[i];
    vector<int> p;
    REP(i, 8) {
        bool exists = false;
        REP(j, n) {
            if (i == c[j]) {
                exists = true;
            }
        }
        if (!exists) p.push_back(i);
    }
    sort(ALL(p));
    do {
        vector<string> s(8, "........");
        vector<int> rc(8, -1);
        REP(i, n) rc[r[i]] = c[i];
        for (int v : p) {
            REP(i, 8) {
                if (rc[i] == -1) {
                    rc[i] = v;
                    break;
                }
            }
        }
        REP(i, 8) { s[i][rc[i]] = 'Q'; }
        if (f(s)) {
            REP(i, 8) output(s[i]);
            return 0;
        }
    } while (next_permutation(ALL(p)));
    assert(false);
}
