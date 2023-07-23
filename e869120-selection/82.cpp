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
template <class T> struct Imos {
   public:
    Imos(int n) : n(n), data(n + 1, 0){};

    // [l, r)
    void add(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= n);
        data[l] += x;
        data[r] -= x;
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            data[i + 1] += data[i];
        }
    }

    T get(int idx) {
        assert(0 <= idx && idx < n);
        return data[idx];
    }

   private:
    int n;
    vector<T> data;
};

vector<string> split(string s, char c) {
    vector<string> ans;
    string t = "";
    REP(i, s.length()) {
        if (s[i] == c) {
            ans.push_back(t);
            t = "";
        } else {
            t += s[i];
        }
    }
    ans.push_back(t);
    return ans;
}

int main() {
    vector<int> ans;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        Imos<int> imos(24 * 60 * 60 + 60 * 60 + 60);
        REP(i, n) {
            vector<int> a(2);
            REP(j, 2) {
                string str;
                cin >> str;
                auto t = split(str, ':');
                int h = stoi(t[0]);
                int m = stoi(t[1]);
                int s = stoi(t[2]);
                a[j] = h * 60 * 60 + m * 60 + s;
            }
            imos.add(a[0], a[1], 1);
        }
        imos.build();
        int tmp = -1;
        REP(i, 24 * 60 * 60 + 60 * 60 + 60) { chmax(tmp, imos.get(i)); }
        ans.push_back(tmp);
    }
    REP(i, (int)ans.size()) { output(ans[i]); }
}
