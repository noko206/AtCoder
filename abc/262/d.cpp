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
	ll ans = 0;
	REP(i, 1, n){
		vector<int> b(n);
		REP(j, n){
			b[i] = a[i] % i;
		}
		vector<map<int, ll>> dp(n);
		dp[0][0] = 1;
		dp[0][b[0]] = 1;
		REP(j, n - 1){
			for(auto p : dp[j]){
				int k = p.first;
				ll val = p.second;
				dp[j + 1][k] += val;
				dp[j + 1][k] %= mod;
				dp[j + 1][b[j + 1] + k] += val;
				dp[j + 1][b[j + 1] + k] %= mod;
			}
		}
		for(auto p : dp[]){
			int k = p.first;
			ll val = p.second;
			if(k % i == 0){
				ans += val;
			}
		}
	}
	cout << ans << endl;
}