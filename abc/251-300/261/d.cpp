#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1000000007;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	REP(i, n){
		cin >> x[i];
	}
	unordered_map<int, int> bonus;
	REP(i, m){
		int c, y;
		cin >> c >> y;
		bonus[c] = y;
	}
	vector<vector<ll>> dp(n + 1);
	dp[0].resize(1, 0);
	REP(i, n){
		dp[i + 1].resize(i + 2, 0);
		REP(j, i + 1){
			chmax(dp[i + 1][0], dp[i][j]);
			if(bonus.find(j + 1) == bonus.end()){
				chmax(dp[i + 1][j + 1], dp[i][j] + x[i]);
			}
			else{
				chmax(dp[i + 1][j + 1], dp[i][j] + x[i] + bonus[j + 1]);
			}
		}
	}
	ll ans = 0;
	REP(i, n + 1){
		chmax(ans, dp[n][i]);
	}
	cout << ans << endl;
	// REP(i, n + 1){
	// 	REP(j, i + 1){
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
}