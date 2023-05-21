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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	vector<vector<int>> cnt(41, vector<int>(2, 0));
	REP(i, n){
		REP(j, 41){
			if(a[i] & (1 << j)) ++cnt[j][1];
			else ++cnt[j][0];
		}
	}
	ll x = 0;
	ll ans = 0;
	RREP(i, 40){
		vector<int> cnt(2, 0);
		REP(j, n){
			if(a[j] & (1LL << i)) ++cnt[1];
			else ++cnt[0];
		}
		if(cnt[1] < cnt[0] && x + (1LL << i) <= k){
			x += 1LL << i;
			ans += (1LL << i) * cnt[0];
		}
		else{
			ans += (1LL << i) * cnt[1];
		}
	}
	output(ans);
}