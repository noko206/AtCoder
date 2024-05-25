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
    string s;
    cin >> s;
    if (s.length() == 1) {
        output(s);
        return 0;
    }
    stack<int> st;
    int cntS = 0;
    vector<int> pos(s.length(), -1);
    REP(i, s.length()) {
        if (s[i] == '(') {
            st.push(i);
            ++cntS;
        } else if (s[i] == ')') {
            pos[i] = st.top();
            pos[st.top()] = i;
            st.pop();
            --cntS;
        } else if (cntS % 2 == 1) {
            if ('a' <= s[i] && s[i] <= 'z') {
                s[i] = s[i] - 'a' + 'A';
            } else {
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }
    string ans = "";
    auto dfs = [&](auto &dfs, int from, int to) -> void {
        if (from == to) return;
        if (from < to) {
            // 左から右
            for (int i = from; i <= to; ++i) {
                if (s[i] == '(') {
                    // 入れ子
                    assert(i < pos[i]);
                    assert(pos[i] != -1);
                    dfs(dfs, pos[i] - 1, i);
                    i = pos[i];
                } else if (s[i] == ')') {
                    // 終了条件
                    return;
                } else {
                    ans += s[i];
                }
            }
        } else {
            // 右から左
            for (int i = from; i >= to; --i) {
                if (s[i] == ')') {
                    // 入れ子
                    assert(pos[i] < i);
                    assert(pos[i] != -1);
                    dfs(dfs, pos[i] + 1, i);
                    i = pos[i];
                } else if (s[i] == '(') {
                    // 終了条件
                    return;
                } else {
                    ans += s[i];
                }
            }
        }
    };
    dfs(dfs, 0, s.length() - 1);
    output(ans);
}
