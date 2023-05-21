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

int main(){
	int n, m;
	ll k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	int x_cnt = 0;
	REP(i, n){
		if(s[i] == 'x') ++x_cnt;
	}
	if(x_cnt * m == k){
		output((ll)n * m);
		return 0;
	}
	ll kukan = k / x_cnt;
	ll amari = k % x_cnt;
	ll ans = 0;
	if(m - kukan == 1){
		--kukan;
		amari += x_cnt;
	}
	if(kukan > 0) ans += kukan * n;
	if(m != 1){
		s += s;
		n = s.length();
	}
	int j = 0;
	int mx = 0;
	int cnt = 0;
	REP(i, n){
		while(j < n){
			if(s[j] == 'x'){
				++cnt;
			}
			++j;
			if(cnt > amari) break;
		}
		if(i == 0 || j == n || (i < n / 2 && n / 2 <= j)){
			chmax(mx, j - i - 1);
		}
		if(s[i] == 'x'){
			--cnt;
		}
	}
	ans += mx;
	output(ans);
}