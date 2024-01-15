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

ll dp[10005][2];

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	REP(i, k) cin >> a[i];
	REP(i, n + 1){
		REP(j, 2){
			dp[i][j] = -1;
		}
	}
	dp[n][1] = 0; // 1:青木/0:高橋
	for(int i = n; i >= 0; --i){
		REP(j, k){
			REP(l, 2){
				if(i + a[j] > n) continue;
				if(dp[i + a[j]][(l + 1) % 2] == -1) continue;
				chmax(dp[i][l], n - (dp[i + a[j]][(l + 1) % 2] + i));
			}
		}
	}
	// ll ans = 0;
	// REP(i, n + 1){
	// 	if(dp[i][0] != -1) chmax(ans, dp[i][0]);
	// 	if(dp[i][1] != -1) chmax(ans, n - (dp[i][1] + i));
	// }
	// cout << ans << endl;
	// REP(i, 2){
	// 	REP(j, 10){
	// 		cout << dp[j][i] << ' ';
	// 	}
	// 	cout << endl;
	// }
}