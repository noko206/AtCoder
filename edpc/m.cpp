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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	int mod = 1000000007;
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
	dp[0][0] = 1;
	REP(i, n){
		ll tot = 0;
		REP(j, k + 1){
			tot += dp[i][j];
			tot %= mod;

			if(j - (a[i] + 1) >= 0){
				tot -= dp[i][j - (a[i] + 1)];
				tot += mod;
				tot %= mod;
			}

			dp[i + 1][j] = tot;
			dp[i + 1][j] %= mod;
		}
	}
	cout << dp[n][k] << endl;
}