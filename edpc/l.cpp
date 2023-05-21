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
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<vector<ll>> dp(n, vector<ll>(n, -INF64));
	auto dfs = [&](auto &dfs, int i, int j) -> ll {
		if(j < i) return 0;
		if(dp[i][j] != -INF64) return dp[i][j];
		ll res = 0;
		if((n - (j - i)) % 2 == 0){
			res = min(dfs(dfs, i + 1, j) - a[i], dfs(dfs, i, j - 1) - a[j]);
		}
		else{
			res = max(dfs(dfs, i + 1, j) + a[i], dfs(dfs, i, j - 1) + a[j]);
		}
		return dp[i][j] = res;
	};
	dfs(dfs, 0, n - 1);
	cout << dp[0][n - 1] << endl;
}