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
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

struct Edge {
	long long to;
	long long cost;
	int idx;
};
using Graph = vector<vector<Edge>>;
using P = pair<long long, int>;

int main(){
	int n, m;
	cin >> n >> m;
	Graph G(n);
	REP(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		Edge e1, e2;
		e1.to = b;
		e1.cost = c;
		e1.idx = i;
		e2.to = a;
		e2.cost = c;
		e2.idx = i;
		G[a].push_back(e1);
		G[b].push_back(e2);
	}
	vector<int> ans;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.emplace(0, 0);
	vector<ll> dist(n, LLINF);
	dist[0] = 0;
	while(!pq.empty()){
		P p = pq.top();
		pq.pop();
		ll c = p.first;
		int v = p.second;
		if(dist[v] < c) continue;
		for(Edge u : G[v]) {
			if (chmin(dist[u.to], c + u.cost)){
				ans.push_back(u.idx);
				pq.emplace(dist[u.to], u.to);
			}
		}
	}
	for(int v : ans){
		cout << v + 1 << ' ';
	}
	cout << endl;
	REP(i, n){
		cout << dist[i] << endl;
	}
}