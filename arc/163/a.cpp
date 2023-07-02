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
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
bool solve(int n, string s) {
    int start = s[0];
    REP(i, 1, n) {
        if (start < s[i]) return true;
    }
    unordered_set<int> st;
    REP(i, 1, n) {
        if (s[i] == start) st.insert(i);
    }
    queue<int> q;
    REP(i, n) {
        for (int pos : st) {
            if (i + pos >= n) {
                q.push(pos);
                continue;
            }
            if (i == pos) return true;
            if (s[i] > s[i + pos]) {
                q.push(pos);
                continue;
            }
            if (s[i] < s[i + pos]) return true;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            st.erase(v);
        }
    }
    return false;
}

bool naive(int n, string s) {
    string start = "";
    string end = s;

    REP(i, n - 1) {
        start += s[i];
        end = end.substr(1);
        if (start < end) return true;
    }
    return false;
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
    //　英小文字の例
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

int main() {
    int t;
    cin >> t;
    vector<bool> ans(t);
    REP(i, t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ans[i] = solve(n, s);
    }
    REP(i, t) { YesNo(ans[i]); }

    // REP(i, 1000) {
    //     string tmp = genRandomStringLower(10);
    //     if (solve(10, tmp) != naive(10, tmp)) {
    //         output(tmp, solve(10, tmp), naive(10, tmp));
    //     }
    // }
}