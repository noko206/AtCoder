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
ll solve(string s, string t) {
    int n = s.length(), m = t.length();
    vector next(26, vector<int>(n));
    REP(c, 26) {
        int pos = INF32;
        RREP(i, n - 1) {
            if (s[i] == c + 'a') {
                pos = i;
            }
            next[c][i] = pos;
        }
    }
    ll ans = 0;
    REP(left, n) {
        int right = left - 1;
        REP(i, m) {
            if (right + 1 >= n) {
                right = n;
                break;
            }
            right = next[t[i] - 'a'][right + 1];
        }
        if (right >= n) right = n;
        ans += right - left;
    }
    return ans;
}

ll naive(string s, string t) {
    int n = s.length(), m = t.length();
    ll ans = 0;
    REP(left, n) {
        REP(right, left, n) {
            int pos = 0;
            REP(i, left, right + 1) {
                if (pos == m) break;
                if (s[i] == t[pos]) {
                    ++pos;
                }
            }
            if (pos != m) {
                ++ans;
            }
        }
    }
    return ans;
}

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

char getRandomCharLower(void) {
    const char CHARS[] = "abcdefghijklmnopqrstuvwxyz";
    int index = genRand(0, (strlen(CHARS) - 1));
    char c = CHARS[index];
    return c;
}

string genRandomStringLower(int length) {
    string text(length, '.');
    generate_n(text.begin(), length, getRandomCharLower);
    return text;
}

void test() {
    REP(_, 10000) {
        string s = genRandomStringLower(5);
        string t = genRandomStringLower(1);
        ll ans_solve = solve(s, t);
        ll ans_naive = naive(s, t);
        if (ans_solve != ans_naive) {
            output(ans_solve, ans_naive, s, t);
            return;
        }
    }
}

int main() {
    // test();
    // return 0;
    string s, t;
    cin >> s >> t;
    output(solve(s, t));
}
