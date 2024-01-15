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

bool dp[105][10005];

int main(){
	int n, s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	REP(i, n){
		cin >> a[i] >> b[i];
	}
	dp[0][0] = true;
	REP(i, n){
		REP(j, 10001){
			if(j + a[i] <= 10000 && dp[i][j]){
				dp[i + 1][j + a[i]] = true;
			}
			if(j + b[i] <= 10000 && dp[i][j]){
				dp[i + 1][j + b[i]] = true;
			}
		}
	}
	if(!dp[n][s]){
		cout << "No" << endl;
		return 0;
	}
	// REP(i, n + 1){
	// 	REP(j, 12){
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// return 0;
	string ans = "";
	int j = s;
	for(int i = n; i > 0; --i){
		if(j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]]){
			j -= a[i - 1];
			ans += 'H';
			continue;
		}
		if(j - b[i - 1] >= 0 && dp[i - 1][j - b[i - 1]]){
			j -= b[i - 1];
			ans += 'T';
			continue;
		}
		// cout << i << endl;
		cout << "No" << endl;
		return 0;
	}
	reverse(ALL(ans));
	cout << "Yes" << endl;
	cout << ans << endl;
}