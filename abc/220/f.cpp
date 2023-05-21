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

using Graph = vector<vector<int>>;

int main(){
	int n;
	cin >> n;
	Graph G(n);
	REP(i, n - 1){
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> cnt(n);
	auto dfs1 = [&](auto &self, int v, int p = -1) -> int {
		int tot = 1;
		for(int u : G[v]){
			if(u == p) continue;
			tot += self(self, u, v);
		}
		cnt[v] = tot;
		return tot;
	};
	dfs1(dfs1, 0);
	vector<ll> ans(n);
	auto dfs2 = [&](auto &self, int v, int p = -1, int depth = 0) -> void {
		ans[0] += depth;
		for(int u : G[v]){
			if(u == p) continue;
			self(self, u, v, depth + 1);
		}
	};
	dfs2(dfs2, 0);
	auto dfs3 = [&](auto &self, int v, int p = -1) -> void {
		for(int u : G[v]){
			if(u == p) continue;
			ans[u] = ans[v] + (n - cnt[u]) - cnt[u];
			self(self, u, v);
		}
	};
	dfs3(dfs3, 0);
	REP(i, n){
		cout << ans[i] << endl;
	}
}