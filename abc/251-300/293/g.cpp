#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<ll> dp(n + 1, 0);
	vector<ll> cnt(200005, 0);
	ll tot = 0;
	REP(i, n){
		if(cnt[a[i]] <= 1){
			dp[i + 1] = dp[i];
		}
		else{
			ll tmp = cnt[a[i]] * (cnt[a[i]] - 1) / 2;
			dp[i + 1] = dp[i] + tmp;
		}
		++cnt[a[i]];
	}
	vector<ll> ans(q);
	REP(i, q){
		int l, r;
		cin >> l >> r;
		--l;
		ans[i] = dp[r] - dp[l];
	}
	REP(i, n + 1) cout << dp[i] << ' ';
	cout << endl;
	REP(i, q) cout << ans[i] << endl;
}