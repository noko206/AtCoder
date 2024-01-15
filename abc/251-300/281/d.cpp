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

ll dp[105][105][105];

int main(){
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	REP(i, n + 1) REP(j, k + 1) REP(l, d) dp[i][j][l] = -1;
	dp[0][0][0] = 0;
	REP(i, n){
		REP(j, k + 1){
			REP(l, d){
				if(dp[i][j][l] == -1) continue;
				if(j < k) chmax(dp[i + 1][j + 1][(l + a[i]) % d], dp[i][j][l] + a[i]);
				chmax(dp[i + 1][j][l], dp[i][j][l]);
			}
		}
	}
	cout << dp[n][k][0] << endl;
}