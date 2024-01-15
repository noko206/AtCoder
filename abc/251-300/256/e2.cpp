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

int main(){
	int n;
	cin >> n;
	vector<int> x(n), c(n);
	REP(i, n){
		cin >> x[i];
		--x[i];
	}
	REP(i, n){
		cin >> c[i];
	}
	vector<bool> visited(n, false);
	ll ans = 0;
	REP(i, n){
		if(visited[i]) continue;
		int v = i;
		map<int, bool> mp;
		while(true){
			if(visited[v]) break;
			mp[v] = true;
			visited[v] = true;
			v = x[v];
		}
		if(mp.find(v) != mp.end()){
			int mi = INF32;
			mp.clear();
			while(true){
				if(mp.find(v) != mp.end()) break;
				mp[v] = true;
				chmin(mi, c[v]);
				v = x[v];
			}
			ans += mi;
		}
	}
	cout << ans << endl;
}