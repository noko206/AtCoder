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
bool f(string s, int k) {
    int n = s.size();

    vector<int> rad(n);
    int c = 0, r = 0;

    while (c < n) {
        // cを中心に同じ文字がどこまで連続するか
        while (0 <= c - r && c + r < n && s[c - r] == s[c + r]) r++;
        rad[c] = r;

        // 回文の長さに応じて利用可能な範囲を確認しつつメモ
        int k = 1;
        while (0 <= c - k && k + rad[c - k] < r) {
            rad[c + k] = rad[c - k];
            k++;
        }
        // すでに計算が終わった分だけ中心と探索半径をずらす
        c += k;
        r -= k;
    }
    // output(s);
    REP(i, n) {
        int r = rad[i] * 2 - 1;
        if (r == 1) continue;
        r /= 2;
        if (r >= k && r % 2 == k % 2) {
            // output(i, r);
            return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    {
        set<char> st;
        REP(i, s.length()) { st.insert(s[i]); }
        if (st.size() == n) {
            int ans = 1;
            REP(i, n) { ans *= i + 1; }
            output(ans);
            return 0;
        }
    }
    sort(ALL(s));
    unordered_set<string> st;
    do {
        st.insert(s);
    } while (next_permutation(ALL(s)));
    int ans = 0;
    for (string t : st) {
        string u = ".";
        REP(i, t.length()) {
            u += t[i];
            u += ".";
        }
        if (f(u, k)) {
            ++ans;
        }
    }
    output(ans);
}
