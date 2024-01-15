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

ll dp[1005];

int main(){
	int n;
	string s;
	cin >> n >> s;
	dp[0] = 1;
	int mod = MOD998244353;
	vector<vector<int>> pos(n, vector<int>(10, -1));
	vector<int> tmp(10, -1);
	REP(i, n){
		REP(j, 10){
			pos[i][j] = tmp[j];
		}
		tmp[s[i] - 'A'] = i;
	}
	REP(i, n){
		int j = i;
		while(pos[j][s[j] - 'A'] != -1){
			j = pos[j][s[j] - 'A'];
		}
		dp[i + 1] = dp[i] + dp[j];
		dp[i + 1] %= mod;
	}
	REP(i, n + 1){
		cout << dp[i] << ' ';
	}
	cout << endl;
}