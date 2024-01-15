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

int main(){
	int n;
	cin >> n;
	int mod = MOD998244353;
	vector<int> a(n);
	REP(i, n){
		cin >> a[i];
	}
	vector<vector<vector<vector<ll>>>> dp(n + 1);
	dp[0].resize(2);
	dp[0][j].resize(n + 1);
	REP(i, n){
		
		dp[i + 1].resize(1 + 3);
		REP(j, i + 1){
			
			dp[i + 1][j].resize(n + 1);
			REP(m, 1, n + 1){
				dp[i][j][m].resize(m, 0);
				dp[i][j][m].resize();
				REP(k, m){
					dp[i + 1][j][m][k] += dp[i][j][m][k];
					cout << 'a' << endl;
					dp[i + 1][j][m][k] %= mod;
					dp[i + 1][j + 1][m][(k + a[i]) % m] += dp[i][j][m][k];
					dp[i + 1][j + 1][m][(k + a[i]) % m] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	REP(i, 1, 101){
		ans += dp[n][i][i][0];
	}
	cout << ans << endl;
}