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

// 行列積
vector<vector<ll>> matrix_mul(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				res[i][j] ^= a[i][k] & b[k][j];
			}
		}
	}
	return res;
}

// 行列累乗
vector<vector<ll>> matrix_pow(vector<vector<ll>> a, ll n) {
	vector<vector<ll>> res(a.size(), vector<ll>(a.size()));
	// 単位行列で初期化
	for (int i = 0; i < a.size(); i++) {
		res[i][i] = (1LL << 32) - 1;
	}
	// 繰り返し二乗法
	while (n > 0) {
		if (n & 1) res = matrix_mul(a, res);
		a = matrix_mul(a, a);
		n >>= 1;
	}
	return res;
}

int main(){
	int k, m;
	cin >> k >> m;
	vector<ll> a(k), c(k);
	REP(i, k) cin >> a[i];
	REP(i, k) cin >> c[i];
	if(m <= k){
		output(a[m - 1]);
		return 0;
	}
	vector<vector<ll>> mat(k, vector<ll>(k, 0));
	REP(i, k) mat[0][i] = c[i];
	REP(i, k - 1) mat[i + 1][i] = (1LL << 32) - 1;
	ll n = m - k;
	auto mat_pow = matrix_pow(mat, n);
	vector<vector<ll>> a_mat(k, vector<ll>(1));
	REP(i, k) a_mat[i][0] = a[k - i - 1];
	auto ans = matrix_mul(mat_pow, a_mat);
	output(ans[0][0]);
}