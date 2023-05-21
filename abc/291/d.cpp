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

ll dp[200005][2][2];

int main(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	REP(i, n) cin >> a[i] >> b[i];
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	int mod = 998244353;
	REP(i, n - 1){
		if(b[i] != b[i + 1]) dp[i + 1][0][0] += dp[i][0][0] + dp[i][1][0];
		if(b[i] != a[i + 1]) dp[i + 1][0][1] += dp[i][0][0] + dp[i][1][0];
		if(a[i] != b[i + 1]) dp[i + 1][1][0] += dp[i][0][1] + dp[i][1][1];
		if(a[i] != a[i + 1]) dp[i + 1][1][1] += dp[i][0][1] + dp[i][1][1];
		REP(j, 2) REP(k, 2) dp[i + 1][j][k] %= mod;
	}
	ll ans = 0;
	REP(j, 2) REP(k, 2) ans += dp[n - 1][j][k];
	ans %= mod;
	cout << ans << endl;
}