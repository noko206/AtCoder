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

const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, 0, 1};

// unordered_mapのキーをpair型にしたいとき
struct HashPair {

	static size_t m_hash_pair_random;

	template<class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const {

		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);

		size_t seed = 0;
		seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		return seed;
	}
};

size_t HashPair::m_hash_pair_random = (size_t) random_device()();
// map<pair<int, int>, int> mp;

int main(){
	int n;
	cin >> n;
	UnionFind uf(n);
	map<pair<int, int>, int> mp;
	vector<int> x(n), y(n);
	REP(i, n){
		cin >> x[i] >> y[i];
		mp[{x[i], y[i]}] = i;
	}
	REP(i, n){
		REP(j, 6){
			int nx = x[i] + dx[j];
			int ny = y[i] + dy[j];
			if(mp.find({nx, ny}) != mp.end() && !uf.same(mp[{nx, ny}], i)){
				uf.unite(mp[{nx, ny}], i);
			}
		}
	}
	ll ans = 0;
	vector<bool> checked(n, false);
	REP(i, n){
		int r = uf.root(i);
		if(!checked[r]){
			++ans;
			checked[r] = true;
		}
	}
	cout << ans << endl;
}