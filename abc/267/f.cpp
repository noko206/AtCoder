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
	REP(i, n - 1){
		int a, b;
		cin >> a >> b;
		--a; --b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	auto dfs = [&](auto &dfs, int v, int p, int cnt) -> pair<int, int> {
		int ans = v;
		int dist = 0;
		for(int u : to[v]){
			if(u == p) continue;
			pair<int, int> p = dfs(dfs, u, v, cnt + 1);
			if(p.second > dist){
				ans = p.first;
				dist = p.second;
			}
		}
		return {ans, dist};
	};
	pair<int, int> p = dfs(dfs, 0, -1, 0);
	int L = p.first;
	p = dfs(dfs, L, -1, 0);
	int R = p.first;
	vector<int> distL(n);
	auto dfs2 = [&](auto &dfs2, int v, int p) -> void {
		if(p == -1) distL[v] = 0;
		else distL[v] = distL[p] + 1;
		for(int u : to[v]){
			if(u == p) continue;
			dfs2(dfs2, u, v);
		}
	};
	dfs2(dfs2, 0, -1);
	vector<int> distR(n);
	auto dfs3 = [&](auto &dfs3, int v, int p) -> void {
		if(p == -1) distR[v] = 0;
		else distR[v] = distR[p] + 1;
		for(int u : to[v]){
			if(u == p) continue;
			dfs3(dfs3, u, v);
		}
	};
	dfs3(dfs3, 0, -1);

	vector<vector<int>> dist_to_numL(n), dist_to_numR(n);
	REP(i, n){
		dist_to_numL[distL[i]].push_back(i);
		dist_to_numR[distR[i]].push_back(i);
	}
	int q;
	cin >> q;
	vector<int> ans(q);
	REP(i, q){
		int u, k;
		cin >> u >> k;
		--u;
		if(k >= distL[u])
		if(dist[u] - k >= 0 && dist_to_num[dist[u] - k].size() > 0){
			ans[i] = dist_to_num[dist[u] - k][0] + 1;
			continue;
		}

		ans[i] = -1;
	}
	REP(i, q){
		cout << ans[i] << endl;
	}
}