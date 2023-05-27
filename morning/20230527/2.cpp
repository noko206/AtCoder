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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	int zero_cnt = 0;
	REP(i, n){
		if(s[i] != t[i]){
			++cnt;
			if(s[i] == '0') ++zero_cnt;
		}
	}
	if(cnt % 2 == 1){
		output(-1);
		return 0;
	}
	string u = "";
	int one_cnt = cnt - zero_cnt;
	int one_put = min(one_cnt, zero_cnt);
	int zero_put = one_put;
	assert((one_cnt - one_put) % 2 == 0);
	assert((zero_cnt - zero_put) % 2 == 0);
	if(one_put < one_cnt) one_put += (one_cnt - one_put) / 2;
	if(zero_put < zero_cnt) zero_put += (zero_cnt - zero_put) / 2;
	REP(i, n){
		if(s[i] == t[i]) u += '0';
		else{
			if(s[i] == '0'){
				if(zero_put > 0) u += '0';
				else u += '1';
				--zero_put;
			}
			else{
				if(one_put > 0) u += '0';
				else u += '1';
				--one_put;
			}
		}
	}
	output(u);
}