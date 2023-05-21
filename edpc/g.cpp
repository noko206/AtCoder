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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> to(n);
	REP(i, m){
		int x, y;
		cin >> x >> y;
		--x; --y;
		to[x].push_back(y);
	}
	// メモ化再帰(更新順序が非自明なので)
	vector<int> dp(n, -1);
	auto dfs = [&](auto &dfs, int v) -> int {
		if(dp[v] != -1) return dp[v];
		for(int u : to[v]){
			chmax(dp[v], dfs(dfs, u) + 1);
		}
		if(dp[v] == -1) dp[v] = 0;
		return dp[v];
	};
	REP(i, n){
		if(dp[i] == -1){
			dfs(dfs, i);
		}
	}
	cout << *max_element(ALL(dp)) << endl;
}