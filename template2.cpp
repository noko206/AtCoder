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

ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

// 桁数を指定して出力したいとき
// std::cout << std::setprecision(2) << 3.141; // "3.1"

// __int128を使う場合, ifで定数と比較する場合はキャストする必要あり
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
	std::ostream::sentry s(dest);
	if (s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if (value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}

// Union-Find
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

// セグ木
class SegmentTree {
private:
	int sz;
	vector<int> seg;
	vector<int> lazy;
	void push(int k) {
		if (k < sz) {
			lazy[k * 2] = max(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
		}
		seg[k] = max(seg[k], lazy[k]);
		lazy[k] = 0;
	}
	void update(int a, int b, int x, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k);
			return;
		}
		update(a, b, x, k * 2, l, (l + r) >> 1);
		update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
	}
	int range_max(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return seg[k];
		int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
		int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
		return max(lc, rc);
	}
public:
	segment_tree() : sz(0), seg(), lazy() {};
	segment_tree(int N) {
		sz = 1;
		while (sz < N) {
			sz *= 2;
		}
		seg = vector<int>(sz * 2, 0);
		lazy = vector<int>(sz * 2, 0);
	}
	void update(int l, int r, int x) {
		update(l, r, x, 1, 0, sz);
	}
	int range_max(int l, int r) {
		return range_max(l, r, 1, 0, sz);
	}
};

class LazySegmentTree {
private:
	int n;
	vector<ll> node, lazy;

public:
	LazySegmentTree(vector<ll> v) {
		int sz = (int)v.size();
		n = 1; while(n < sz) n *= 2;
		node.resize(2*n-1);
		lazy.resize(2*n-1, 0);

		for(int i=0; i<sz; i++) node[i+n-1] = v[i];
		for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
	}

	void eval(int k, int l, int r) {
		if(lazy[k] != 0) {
			node[k] += lazy[k];
			if(r - l > 1) {
				lazy[2*k+1] += lazy[k] / 2;
				lazy[2*k+2] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}

	void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return;
		if(a <= l && r <= b) {
			lazy[k] += (r - l) * x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2*k+1, l, (l+r)/2);
			add(a, b, x, 2*k+2, (l+r)/2, r);
			node[k] = node[2*k+1] + node[2*k+2];
		}
	}

	ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		eval(k, l, r);
		if(b <= l || r <= a) return 0;
		if(a <= l && r <= b) return node[k];
		ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
		ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
		return vl + vr;
	}
};

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

template<class Monoid> struct SegTree {
	using Func = function<Monoid(Monoid, Monoid)>;
	const Func F;
	const Monoid UNITY;
	int SIZE_R;
	vector<Monoid> dat;

	SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
	void init(int n) {
		SIZE_R = 1;
		while (SIZE_R < n) SIZE_R *= 2;
		dat.assign(SIZE_R * 2, UNITY);
	}

	/* set, a is 0-indexed */
	void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
	void build() {
		for (int k = SIZE_R - 1; k > 0; --k)
			dat[k] = F(dat[k*2], dat[k*2+1]);
	}

	/* update a, a is 0-indexed */
	void update(int a, const Monoid &v) {
		int k = a + SIZE_R;
		dat[k] = v;
		while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
	}

	/* get [a, b), a and b are 0-indexed */
	Monoid get(int a, int b) {
		Monoid vleft = UNITY, vright = UNITY;
		for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
			if (left & 1) vleft = F(vleft, dat[left++]);
			if (right & 1) vright = F(dat[--right], vright);
		}
		return F(vleft, vright);
	}
	inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

	/* debug */
	void print() {
		for (int i = 0; i < SIZE_R; ++i) {
			cout << (*this)[i];
			if (i != SIZE_R-1) cout << ",";
		}
		cout << endl;
	}
};

// ダイクストラ
struct Edge {
	long long to;
	long long cost;
};

using Graph = vector<vector<Edge>>;
using P = pair<long, int>;

void dijkstra(const Graph &G, int s, vector<ll> &dis) {
	int N = G.size();
	dis.resize(N, LLINF);
	priority_queue<P, vector<P>, greater<P>> pq;
	dis[s] = 0;
	pq.emplace(dis[s], s);
	while (!pq.empty()) {
		P p = pq.top();
		pq.pop();
		int v = p.second;
		if (dis[v] < p.first) {
			continue;
		}
		for (auto &e : G[v]) {
			if (dis[e.to] > dis[v] + e.cost) {
				dis[e.to] = dis[v] + e.cost;
				pq.emplace(dis[e.to], e.to);
			}
		}
	}
}

ll mod_pow(ll a, ll n, ll p) {
	if (n == 0) return 1;
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * mod_pow(a, n - 1, p)) % p;
	ll t = mod_pow(a, n / 2, p);
	return (t * t) % p;
}

ll mod_inv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

ll mod_conb(ll a, ll b, ll m) {
	ll ans = 1;
	for(int i = 0; i < b; ++i){
		ans *= a - i;
		ans %= m;
	}
	for(int i = 0; i < b; ++i){
		ans *= mod_inv(i + 1, m);
		ans %= m;
	}
	return ans;
}

// 重複組み合わせ
ll mod_cnt_multi(ll a, ll b, ll m){
	if(a == 0 && b == 0) return 1;
	if(a <= 0 || b < 0) return 0;
	return mod_conb(a + b - 1, b, m);
}

/* encode: ランレングス圧縮を行う
*/
vector<pair<char, int>> encode(const string str) {
	int n = (int)str.size();
	vector<pair<char, int>> ret;
	for (int l = 0; l < n;) {
		int r = l + 1;
		for (; r < n && str[l] == str[r]; r++) {};
		ret.push_back({str[l], r - l});
		l = r;
	}
	return ret;
}
/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, int>> code) {
	string ret = "";
	for (auto p : code) {
		for (int i = 0; i < p.second; i++) {
			ret.push_back(p.first);
		}
	}
	return ret;
}

// main
int main(){
	// bit全探索
	REP(bit, 1 << n){
		REP(i, n){
			if(!(bit & (1 << i))){
				continue;
			}
			// bitが立った時の処理(i)
		}
	}

	// bit全探索(on and off)
	REP(bit, 1 << n){
		REP(i, n){
			if((bit & (1 << i))){
				// bitが立った時の処理
			}
			else{
				// bitが立たなかった時の処理
			}
		}
	}

	// 幅優先探索
	queue<int> q;
	q.push(0);
	while(q.size()){
		int v = q.front();
		q.pop();
		for(int next : G[v]){
			if(next == v){
				continue;
			}
			// ここに幅優先探索の処理
			q.push(next);
		}
	}

	// 順列全列挙
	vector<int> np(n);
	REP(i, n){
		np[i] = i;
	}
	do{
		REP(i, n){

		}
	} while (next_permutation(ALL(np)));

	// しゃくとり法
	// iが後ろ,jが前
	// map<int, int> mp;
	// int j = 0, cnt = 0, ans = 0;
	// REP(i, n){
	//     while(j < n){
	//         if(mp[a[j]] == 0 && cnt == k){
	//             break;
	//         }
	//         if(mp[a[j]] == 0){
	//             ++cnt;
	//         }
	//         ++mp[a[j]];
	//         ++j;
	//     }
	//     chmax(ans, j - i);
	//     --mp[a[i]];
	//     if(mp[a[i]] == 0){
	//         --cnt;
	//     }
	// }
}