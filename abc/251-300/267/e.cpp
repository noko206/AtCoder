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

class UnionFind {
private:
	vector<int> par;
	vector<int> siz;

public:
	UnionFind(int n){
		for (int i = 0; i < n; i++){
			par.push_back(i);
		}
		siz.resize(n, 1);
	}

	int root(int x) {
		if(par[x] == x){
			return x;
		}
		return par[x] = root(par[x]);
	}

	bool unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if(rx == ry){
			return false;
		}
		if(siz[rx] < siz[ry]){
			swap(rx, ry);
		}
		siz[rx] += siz[ry];
		par[ry] = rx;
		return true;
	}

	bool same(int x, int y){
		return root(x) == root(y);
	}

	int size(int x){
		return siz[root(x)];
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<int> to(n);
	REP(i, m){
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	ll ok = INF64;
	ll ng = -1;
	REP(ok - ng != 1){
		ll mid = (ok + ng) / 2;
		unorderd_map<int, bool> del, visited;
		auto dfs = [&](auto &dfs, int v, int p) -> bool {
			ll cnt = 0;
			visited[v] = true;
			for(int u : to[v]){
				if(del.find(u) != del.end()) continue;
				cnt += a[u];
			}
			if(cnt <= mid) {
				del[v] = true;
				return true;
			}
			for(int u : to[v]){
				if(del.find(u) != del.end()) continue;
				if(u == p) continue;
				if(visited[v]) return false;
				
			}
		};
		REP(i, n){
			if(del.find(i) == del.end()) {
				dfs(dfs, i, -1);
			}
		}
	}
}