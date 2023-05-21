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
	vector<pair<int, string>> queue;
	queue.push_back({x, ""});
	vector<bool> memo(n, false);
	int idx = 0;
	while(true){
		int v = queue[idx].first;
		string ans = queue[idx].second;

		if(v == y){
			cout << ans + to_string(v + 1) << endl;
			return 0;
		}

		memo[v] = true;
		ans += to_string(v + 1) + " ";

		for(int u : to[v]){
			if(memo[u]) continue;
			queue.push_back({u, ans});
		}

		++idx;
	}
}