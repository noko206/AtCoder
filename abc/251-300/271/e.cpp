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

struct Edge {
	int from;
	int to;
	int cost;
};

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<Edge> edge(m);
	REP(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		edge[i] = {a, b, c};
	}
	vector<int> e(k);
	REP(i, k){
		cin >> e[i];
		--e[i];
	}
	vector<ll> dp(n, INF64);
	dp[0] = 0;
	REP(i, k){
		Edge tmp = edge[e[i]];
		int from = tmp.from;
		int to = tmp.to;
		int cost = tmp.cost;
		chmin(dp[to], dp[from] + cost);
	}
	if(dp[n - 1] == INF64) cout << -1 << endl;
	else cout << dp[n - 1] << endl;
}