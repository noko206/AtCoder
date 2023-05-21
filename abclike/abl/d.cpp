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

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n){
		cin >> a[i];
	}
	SegTree<int> dp(300001, [](int a, int b){ return max(a, b); }, 0);
	REP(i, n){
		int low = max(a[i] - k, 0);
		int high = min(a[i] + k, 300000);
		int ma = dp.get(low, high + 1);
		dp.update(a[i], ma + 1);
	}
	int ans = dp.get(0, 300001);
	cout << ans << endl;
}