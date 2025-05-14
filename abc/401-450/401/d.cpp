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
vector<pair<char, int>> run_length_encode(string s) {
    vector<pair<char, int>> ans;
    int i = 0, j = 0, n = s.length();
    while (i < n) {
        while (j < n && s[i] == s[j]) {
            ++j;
        }
        ans.push_back({s[i], j - i});
        i = j;
    }
    return ans;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    {
        int cnt = 0;
        REP(i, n) {
            if (s[i] == 'o') ++cnt;
        }
        if (k == cnt) {
            string t = "";
            REP(i, n) {
                if (s[i] == '?') {
                    t += '.';
                } else {
                    t += s[i];
                }
            }
            output(t);
            return 0;
        }
    }
    string t = s;
    REP(i, n) {
        if (s[i] == 'o') {
            if (i - 1 >= 0 && s[i - 1] == '?') {
                t[i - 1] = '.';
            }
            if (i + 1 < n && s[i + 1] == '?') {
                t[i + 1] = '.';
            }
        }
    }
    {
        // 最大敷き詰めか確認
        auto encode = run_length_encode(t);
        int pos = 0;
        int cnt = 0;
        for (auto [c, len] : encode) {
            if (c == 'o') {
                assert(len == 1);
                ++cnt;
            } else if (c == '?') {
                cnt += (len + 1) / 2;
            }
            pos += len;
        }
        // 敷き詰めを確定
        if (cnt == k) {
            pos = 0;
            for (auto [c, len] : encode) {
                if (c == '?' && len % 2 == 1) {
                    int bit = 0;
                    REP(i, pos, pos + len) {
                        assert(t[i] == '?');
                        t[i] = (bit % 2 == 0) ? 'o' : '.';
                        ++bit;
                    }
                }
                pos += len;
            }
        }
    }
    output(t);
}
