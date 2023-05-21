#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	REP(i, h) cin >> a[i];
	vector<vector<ll>> dp(h, vector<ll>(w, 0));
	dp[0][0] = 1;
	int mod = 1000000007;
	REP(i, h){
		REP(j, w){
			if(a[i][j] == '#') continue;
			if(i - 1 >= 0){
				dp[i][j] += dp[i - 1][j]; dp[i][j] %= mod;
			}
			if(j - 1 >= 0){
				dp[i][j] += dp[i][j - 1]; dp[i][j] %= mod;
			}
		}
	}
	cout << dp[h - 1][w - 1] << endl;
}