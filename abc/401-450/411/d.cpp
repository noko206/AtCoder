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
struct Node {
    vector<int> next;
    int prev;
    char c;
    Node(char c_, int prev_) : c(c_), prev(prev_) { next.resize(27, -1); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> pc(n, 0);
    int server = 0;
    vector<Node> node;
    node.push_back(Node('a' + 26, -1));
    REP(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            --p;
            pc[p] = server;
        } else if (t == 2) {
            int p;
            string s;
            cin >> p >> s;
            --p;
            int node_id = pc[p];
            REP(j, s.length()) {
                if (node[node_id].next[s[j] - 'a'] == -1) {
                    int next_id = node.size();
                    node.push_back(Node(s[j], node_id));
                    node_id = next_id;
                } else {
                    node_id = node[node_id].next[s[j] - 'a'];
                }
            }
            pc[p] = node_id;
        } else {
            int p;
            cin >> p;
            --p;
            server = pc[p];
        }
    }
    int node_id = server;
    vector<char> c;
    while (node[node_id].prev != -1) {
        c.push_back(node[node_id].c);
        node_id = node[node_id].prev;
    }
    reverse(ALL(c));
    string ans = "";
    REP(i, c.size()) { ans += c[i]; }
    output(ans);
}
