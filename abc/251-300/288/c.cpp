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
	UnionFind uf(n);
	int ans = 0;
	REP(i, m){
		int a, b;
		cin >> a >> b;
		--a; --b;
		if(uf.same(a, b)) {
			++ans;
		}
		else{
			uf.unite(a, b);
		}
	}
	cout << ans << endl;
}