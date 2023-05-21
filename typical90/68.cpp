#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

template <class T>
struct BIT {
	int n;
	vector<T> lst;
	BIT(int n_) : n(n_ + 1), lst(n, 0) {}
	void add(int i, T x) {
		++i;
		while (i < n) {
		lst[i] += x;
		i += i & -i;
		}
	}
	// [0,i)
	T sum(int i) {
		T res = 0;
		while (i > 0) {
		res += lst[i];
			i -= i & -i;
		}
		return res;
	}
	// [l,r)
	T sum(int left, int right) { return sum(right) - sum(left); }
};

int main(){
	int n, q;
	cin >> n >> q;
	dsu uf(n);
	BIT<ll> bit(n);
	vector<string> ans;
	while(q--){
		int t, x, y, v;
		cin >> t >> x >> y >> v;
		--x, --y;
		if(t == 0){
			if(uf.same(x, y)) continue;
			uf.merge(x, y);
			if(x % 2 == 0) v *= -1;
			bit.add(x, (ll)v);
		}
		else{
			if(!uf.same(x, y)){
				ans.push_back("Ambiguous");
				continue;
			}
			ll res = bit.sum(max(x, y)) - bit.sum(min(x, y));
			if(x % 2 == 1) v *= -1;
			if(x > y) res *= -1;
			if(y % 2 == 1) {
				res *= -1;
				v *= -1;
			}
			ans.push_back(to_string(res + v));
		}
	}
	for(auto v : ans) cout << v << endl;
}