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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<vector<int>> to(n);
	REP(i, m){
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	multiset<pair<int, ll>> s;
	multiset<pair<ll, int>> sr;
	REP(v, n){
		ll cnt = 0;
		for(int u : to[v]){
			cnt += a[u];
		}
		s.insert({v, cnt});
		sr.insert({cnt, v});
	}
	vector<bool> del(n, false);
	ll ans = -INF64;
	while(!s.empty()){
		auto it = sr.begin();
		pair<ll, int> p = *it;
		int v = p.second;
		ll val = p.first;
		chmax(ans, val);
		del[v] = true;
		ll cnt = 0;
		sr.erase(it);
		s.erase(s.lower_bound({v, val}));
		for(int u : to[v]){
			if(del[u]) continue;
			auto itu = s.lower_bound({u, 0});
			ll valu = (*itu).second;
			s.erase(itu);
			sr.erase(sr.lower_bound({valu, u}));
			valu -= a[v];
			s.insert({u, valu});
			sr.insert({valu, u});
		}
	}
	cout << ans << endl;
}