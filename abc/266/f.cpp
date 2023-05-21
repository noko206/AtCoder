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
	vector<vector<int>> to(n);
	REP(i, n){
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	int q;
	cin >> q;
	vector<bool> visited(n, false), finished(n, false);
	map<int, bool> cycle;
	int c = -1;
	auto dfs = [&](auto &dfs, int v, int p){
		visited[v] = true;
		for(int u : to[v]){
			if(u == p) continue;
			if(finished[u]) continue;
			if(visited[u]){
				c = u;
				return;
			}
			dfs(dfs, u, v);
			if(c != -1) return;
		}
		cycle[c] = true;
		finished[u] = true;
	};
	dfs(dfs, 0, -1);
	map<int, int> left, right;
	REP(i, n){
		visited[i] = false;
	}
	auto dfs2 = [&](auto &dfs2, int v, int p){
		visited[v] = true;
		for(int u : to[v]){
			if(u == p) continue;
			if(visited[u]) continue;
			if(cycle.find(u) == !cycle.end()) continue;
			dfs2(dfs2, u, v);
		}
	};
	REP(v, n){
		if(cycle.find(v) == cycle.end()){

		}
	}
}