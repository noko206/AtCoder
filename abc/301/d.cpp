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
	string s;
	cin >> s;
	ll n;
	cin >> n;
	int m = 0;
	ll tmp = 0;
	REP(i, s.length()) {
		if(s[i] == '?') ++m;
		tmp *= 2;
		if(s[i] == '1') tmp += 1;
	}
	if(tmp > n){
		output(-1);
		return 0;
	}
	if(tmp == n){
		output(n);
		return 0;
	}
	ll ok = 0;
	ll ng = 1LL << m;
	ll ans = tmp;
	while(ng - ok != 1){
		ll mid = (ok + ng) / 2;
		string t = s;
		int cnt = 0;
		RREP(i, t.length() - 1){
			if(t[i] == '?'){
				if(mid & (1LL << cnt)){
					t[i] = '1';
				}
				else{
					t[i] = '0';
				}
				++cnt;
			}
		}
		tmp = 0;
		REP(i, t.length()){
			tmp *= 2;
			if(t[i] == '1') tmp += 1;
		}
		if(tmp <= n) ok = mid, ans = tmp;
		else ng = mid;
	}
	output(ans);
}