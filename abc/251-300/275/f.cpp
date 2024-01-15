#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int MOD1000000007 = 1000000007;
const int MOD998244353 = 998244353;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int dp[3005][3005][2]; // 0:使わない|1:使った

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	REP(i, n + 1){
		REP(j, m + 1){
			REP(k, 2){
				dp[i][j][k] = INF32;
			}
		}
	}
	dp[0][0][0] = 1;
	dp[0][0][1] = 0;
	REP(i, n){
		REP(j, m + 1){
			if(j + a[i] <= m){
				chmin(dp[i + 1][j + a[i]][1], dp[i][j][0]);
				chmin(dp[i + 1][j + a[i]][1], dp[i][j][1]);
			}
			chmin(dp[i + 1][j][0], dp[i][j][0]);
			chmin(dp[i + 1][j][0], dp[i][j][1] + 1);
		}
	}
	REP(i, m){
		int ans = min(dp[n][i + 1][0], dp[n][i + 1][1]);
		if(ans > n) cout << -1 << endl;
		else cout << ans << endl;
	}
}