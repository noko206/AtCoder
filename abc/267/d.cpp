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

ll dp[2005][2005];

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	REP(i, n + 1){
		REP(j, m + 1){
			dp[i][j] = -INF64;
		}
	}
	dp[0][0] = 0;
	REP(i, n){
		REP(j, m + 1){
			chmax(dp[i + 1][j], dp[i][j]);
			if(j + 1 <= m) chmax(dp[i + 1][j + 1], (ll)(j + 1) * a[i] + dp[i][j]);
		}
	}
	ll ans = dp[n][m];
	cout << ans << endl;
}