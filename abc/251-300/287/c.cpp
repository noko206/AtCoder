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
	vector<bool> visited(n, false);
	bool is_ok = true;
	auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
		if(visited[v]) {
			is_ok = false;
			return;
		}
		visited[v] = true;
		for(int u : to[v]){
			if(u == p) continue;
			dfs(dfs, u, v);
		}
	};
	dfs(dfs);
	REP(i, n){
		if(!visited[i]) is_ok = false;
	}
	if(is_ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}