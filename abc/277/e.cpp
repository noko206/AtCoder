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
	int to;
	int a;
};

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<Edge>> G(n);
	REP(i, m){
		int u, v, a;
		cin >> u >> v >> a;
		--u; --v;
		G[u].push_back({v, a});
		G[v].push_back({u, a});
	}
	unordered_map<int, bool> switch_exists;
	REP(i, k){
		int s;
		cin >> s;
		--s;
		switch_exists[s] = true;
	}
	vector<int> dist_on(n, INF32), dist_off(n, INF32);
	dist_off[0] = 0;
	if(switch_exists.find(0) != switch_exists.end()) dist_on[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(Edge e : G[v]){
			int u = e.to;
			int a = e.a;
			if(switch_exists.find(v) != switch_exists.end()){
				if(a == 0){
					if(chmin(dist_on[u], min(dist_on[v] + 1, dist_off[v] + 1))){
						q.push(u);
					}
				}
				else{
					if(chmin(dist_off[u], min(dist_on[v] + 1, dist_off[v] + 1))){
						q.push(u);
					}
				}
			}
			else{
				if(a == 0){
					if(chmin(dist_on[u], dist_on[v] + 1)){
						q.push(u);
					}
				}
				else{
					if(chmin(dist_off[u], dist_off[v] + 1)){
						q.push(u);
					}
				}
			}
		}
	}
	int ans = min(dist_on[n - 1], dist_off[n - 1]);
	if(ans == INF32){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
}