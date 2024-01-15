#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1000000007;
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
	int n;
	cin >> n;
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	vector<int> x(n), y(n), r(n);
	REP(i, n){
		cin >> x[i] >> y[i] >> r[i];
	}
	UnionFind uf(n);
	REP(i, n){
		REP(j, n){
			ll d2 = powl((ll)x[i] - x[j], 2) + powl((ll)y[i] - y[j], 2);
			if(powl(max((ll)r[i] - r[j], (ll)r[j] - r[i]), 2) <= d2 && d2 <= powl((ll)r[i] + r[j], 2)) {
				if(!uf.same(i, j)){
					uf.unite(i, j);
				}
			}
		}
	}
	int s = -1;
	int t = -1;
	REP(i, n){
		if(powl((ll)sx - x[i], 2) + powl((ll)sy - y[i], 2) == (ll)r[i] * r[i]){
			s = i;
		}
		if(powl((ll)tx - x[i], 2) + powl((ll)ty - y[i], 2) == (ll)r[i] * r[i]){
			t = i;
		}
	}
	//cout << s << ' ' << t << endl;
	if(s == -1 || t == -1){
		cout << "No" << endl;
		return 0;
	}
	if(uf.same(s, t)){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}