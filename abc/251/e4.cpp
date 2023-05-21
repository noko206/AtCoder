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

ll dp[300005][2][2];

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n){
		cin >> a[i];
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = INF64;
	dp[0][1][0] = INF64;
	dp[0][1][1] = a[0];
	REP(i, n - 1){
		dp[i + 1][0][0] = dp[i][1][0];
		dp[i + 1][0][1] = dp[i][1][1];
		dp[i + 1][1][0] = min(dp[i][0][0], dp[i][1][0]) + a[i + 1];
		dp[i + 1][1][1] = min(dp[i][0][1], dp[i][1][1]) + a[i + 1];
	}
	cout << min({dp[n - 1][0][1], dp[n - 1][1][0], dp[n - 1][1][1]}) << endl;
}