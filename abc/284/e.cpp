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
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	int ans = 0;
	vector<bool> seen(n, false);
	seen[0] = true;
	auto dfs = [&](auto &dfs, int v) -> void {
		++ans;
		if(ans >= 1000000) return;
		for(int u : to[v]){
			if(ans >= 1000000) return;
			if(seen[u]) continue;
			seen[u] = true;
			dfs(dfs, u);
			seen[u] = false;
		}
	};
	dfs(dfs, 0);
	cout << min(ans, 1000000) << endl;
}