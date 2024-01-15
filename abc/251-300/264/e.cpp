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
	int n, m, e;
	cin >> n >> m >> e;
	vector<bool> is_denki(n + m, true);
	REP(i, n){
		is_denki[i] = false;
	}
	vector<int> u(e), v(e);
	REP(i, e){
		cin >> u[i] >> v[i];
		--u[i]; --v[i];
	}
	int q;
	cin >> q;
	vector<bool> delete_densen(e, false);
	vector<int> x(q);
	REP(i, q){
		cin >> x[i];
		--x[i];
		delete_densen[x[i]] = true;
	}

	UnionFind uf(n + m);
	int tot = 0;
	REP(i, e){
		if(delete_densen[i]) continue;
		if(uf.same(u[i], v[i])) continue;
		bool u_denki = is_denki[uf.root(u[i])];
		bool v_denki = is_denki[uf.root(v[i])];
		if(u_denki && !v_denki){
			tot += uf.size(v[i]);
		}
		if(!u_denki && v_denki){
			tot += uf.size(u[i]);
		}
		uf.unite(u[i], v[i]);
		if(u_denki || v_denki){
			is_denki[uf.root(u[i])] = true;
		}
	}
	vector<int> ans(q);
	ans[0] = tot;
	reverse(ALL(x));
	// REP(i, n){
	// 	cout << is_denki[uf.root(i)] << endl;
	// }
	// return 0;
	REP(idx, q - 1){
		int i = x[idx];
		if(uf.same(u[i], v[i])) {
			ans[idx + 1] = tot;
			continue;
		}
		bool u_denki = is_denki[uf.root(u[i])];
		bool v_denki = is_denki[uf.root(v[i])];
		if(u_denki && !v_denki){
			tot += uf.size(v[i]);
		}
		if(!u_denki && v_denki){
			tot += uf.size(u[i]);
		}
		uf.unite(u[i], v[i]);
		if(u_denki || v_denki){
			is_denki[uf.root(u[i])] = true;
		}
		ans[idx + 1] = tot;
	}
	reverse(ALL(ans));
	REP(i, q){
		cout << ans[i] << endl;
	}
}