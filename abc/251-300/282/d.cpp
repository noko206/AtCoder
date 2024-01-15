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

const int BLACK = 0;
const int WHITE = 1;

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
	// 連結かどうか→UnionFind
	// 初めに白黒の決定をする
	UnionFind uf(n);
	vector<vector<int>> to(n);
	REP(i, m){
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
		to[v].push_back(u);
		uf.unite(u, v);
	}
	vector<int> color(n, -1);
	bool is_nibu = true;
	vector<int> cnt_black(n, 0);
	auto dfs = [&](auto &dfs, int v = 0, int pre_color = BLACK) -> void {
		if(color[v] != -1) return;
		color[v] = (pre_color + 1) % 2;
		if(color[v] == BLACK) ++cnt_black[uf.root(v)];
		for(int u : to[v]){
			if(color[u] == -1){
				dfs(dfs, u, color[v]);
			}
			else{
				if(color[u] == color[v]){
					is_nibu = false;
				}
			}
		}
	};
	REP(i, n){
		if(color[i] == -1){
			dfs(dfs, i);
		}
	}
	if(!is_nibu){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	int all = n;
	set<int> st;
	REP(i, n){
		st.insert(uf.root(i));
	}
	REP(i, n){
		if(color[i] == WHITE){
			ans += cnt_black[uf.root(i)] - to[i].size();
		}
	}
	for(int i : st){
		ans += (ll)uf.size(i) * (ll)(all - uf.size(i));
		all -= uf.size(i);
	}
	cout << ans << endl;
}