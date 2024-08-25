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
// Grundy数をメモ化するためのマップ
unordered_map<int, int> grundy_memo;

// Grundy数を計算する関数
int calculate_grundy(int n) {
    if (n == 1) return 0;  // A_iが1の場合、移動できないのでGrundy数は0

    if (grundy_memo.find(n) != grundy_memo.end()) {
        return grundy_memo[n];  // すでに計算済みならメモを返す
    }

    // 各約数に対してGrundy数を計算する
    unordered_map<int, bool> reachable_states;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            if (d != n) reachable_states[calculate_grundy(d)] = true;
            if (d != 1 && (n / d) != n)
                reachable_states[calculate_grundy(n / d)] = true;
        }
    }

    // Mex (Minimum Excludant) を求める
    int grundy = 0;
    while (reachable_states[grundy]) grundy++;

    // メモ化
    grundy_memo[n] = grundy;
    return grundy;
}

// メイン関数
int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int xor_sum = 0;
    // 各A_iに対してGrundy数を計算しXORを取る
    for (int i = 0; i < N; ++i) {
        xor_sum ^= calculate_grundy(A[i]);
    }

    // XORの結果が0なら後手勝利、0でないなら先手勝利
    if (xor_sum == 0) {
        cout << "Bruno" << endl;
    } else {
        cout << "Anna" << endl;
    }

    return 0;
}