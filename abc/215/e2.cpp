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
	string s;
	cin >> n >> s;
	vector<vector<ll>> dp(1 << 10, vector<ll>(10, 0));
	int mod = MOD998244353;
	REP(i, n){
		vector<vector<ll>> pre = dp;
		int c = s[i] - 'A';
		REP(j, 1 << 10){
			REP(k, 10){
				if(j & (1 << c)){
					if (k == c) {
						dp[j][k] += pre[j][k];
						dp[j][k] %= mod;
					}
				}
				else{
					dp[j | (1 << c)][c] += pre[j][k];
					dp[j | (1 << c)][c] %= mod;
				}
			}
		}
		++dp[1 << c][c];
	}
	ll ans = 0;
	REP(i, 1 << 10){
		REP(j, 10){
			ans += dp[i][j];
			ans %= mod;
		}
	}
	cout << ans << endl;
}