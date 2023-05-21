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

template <typename T>
struct BIT {
	int n;
	vector<T> bit;
	BIT(int n_) : n(n_ + 1), bit(n, 0) {}
	void add(int i, T x) {
		for (int idx = i; idx < n; idx += (idx & -idx)) {
			bit[idx] += x;
		}
	}
	T sum(int i) {
		T s(0);
		for (int idx = i; idx > 0; idx -= (idx & -idx)) {
			s += bit[idx];
		}
		return s;
	}
};

int main(){
	int n, q;
	cin >> n >> q;
	dsu uf(n);
	BIT<ll> even(n), odd(n);
	vector<string> ans;
	REP(i, q){
		int t, x, y, v;
		cin >> t >> x >> y >> v;
		--x, --y;
		if(t == 0){
			if(uf.same(x, y)) continue;
			uf.merge(x, y);
			if(y % 2 == 0){
				even.add(y, v);
			}
			else{
				odd.add(y, v);
			}
		}
		else{
			if(!uf.same(x, y)){
				ans.push_back("Ambiguous");
				continue;
			}
			ll even_sum = even.sum(y) - even.sum(x);
			ll odd_sum = odd.sum(y) - odd.sum(x);
			if(x % 2 == 0){
				if(abs(x - y) % 2 == 0){
					odd_sum *= -1;
				}
				else{
					even_sum *= -1;
				}
			}
			else{
				if(abs(x - y) % 2 == 0){
					even_sum *= -1;
				}
				else{
					odd_sum *= -1;
				}
			}
			if(abs(x - y) % 2 == 1) v *= -1;
			ll tmp = even_sum + odd_sum + v;
			ans.push_back(to_string(tmp));
		}
	}
	for(auto v : ans) cout << v << endl;
}