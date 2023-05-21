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

ll dp[100005][5];

int main(){
	int n;
	cin >> n;
	vector<int> t(n), x(n), a(n);
	REP(i, n){
		cin >> t[i] >> x[i] >> a[i];
	}
	REP(i, 100001){
		REP(j, 5){
			dp[i][j] = -INF64;
		}
	}
	dp[0][0] = 0;
	int i = 0;
	REP(time, 1, 100001){
		if(i < n && t[i] == time){
			REP(j, 5){
				if(j - 1 >= 0) chmax(dp[time][j], dp[time - 1][j - 1]);
				chmax(dp[time][j], dp[time - 1][j]);
				if(j + 1 < 5) chmax(dp[time][j], dp[time - 1][j + 1]);
				if(j == x[i]) dp[time][j] += a[i];
			}
			++i;
		}
		else{
			REP(j, 5){
				if(j - 1 >= 0) chmax(dp[time][j], dp[time - 1][j - 1]);
				chmax(dp[time][j], dp[time - 1][j]);
				if(j + 1 < 5) chmax(dp[time][j], dp[time - 1][j + 1]);
			}
		}
	}
	ll ans = -INF64;
	REP(i, 5){
		chmax(ans, dp[100000][i]);
	}
	cout << ans << endl;
}