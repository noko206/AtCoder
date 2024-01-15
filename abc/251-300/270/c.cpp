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

int main(){
	int n, x, y;
	cin >> n >> x >> y;
	--x; --y;
	vector<vector<int>> to(n);
	REP(i, n - 1){
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	vector<int> ans;
	auto dfs = [&](auto &dfs, int v, int p = -1) -> bool {
		if(v == y) {
			ans.push_back(v);
			return true;
		}
		bool is_ok = false;
		for(int u : to[v]){
			if(u == p) continue;
			if(dfs(dfs, u, v)){
				is_ok = true;
			}
		}
		if(is_ok) ans.push_back(v);
		return is_ok;
	};
	dfs(dfs, x);
	reverse(ALL(ans));
	for(int v : ans){
		cout << v + 1 << ' ';
	}
	cout << endl;
}