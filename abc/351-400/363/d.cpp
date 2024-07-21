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
    ll n;
	cin >> n;
	if (n <= 10) {
		output(n - 1);
		return 0;
	}
	if (n <= 19) {
		cout << n % 10 << n % 10 << endl;
		return 0;
	}
	ll x = 20, y = 110, z = 200, s = 10;
	while(true) {
		if (x <= n && n < y) {
			// 奇数桁
			ll p = n - x;
			ll val = s + p;
			vector<int> vec;
			while (val > 0) {
				vec.push_back(val % 10);
				val /= 10;
			}
			string ans = "";
			RREP(i, vec.size() - 1) {
				ans += (char)(vec[i] + '0');
			}
			REP(i, 1, vec.size()) {
				ans += (char)(vec[i] + '0');
			}
			output(ans);
			return 0;
		}
		if (y <= n && n < z) {
			// 偶数桁
			ll p = n - y;
			ll val = s + p;
			vector<int> vec;
			while (val > 0) {
				vec.push_back(val % 10);
				val /= 10;
			}
			string ans = "";
			RREP(i, vec.size() - 1) {
				ans += (char)(vec[i] + '0');
			}
			REP(i, vec.size()) {
				ans += (char)(vec[i] + '0');
			}
			output(ans);
			return 0;
		}
		x *= 10;
		y *= 10;
		z *= 10;
		s *= 10;
	}
	assert(false);
}
