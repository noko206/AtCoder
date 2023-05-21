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

struct Edge{
	int to;
	int cost;
};
using Graph = vector<vector<Edge>>;
using T = tuple<ll, int, int>;

int main(){
	int n, m;
	cin >> n >> m;
	Graph G(n);
	map<pair<int, int>, int> mp;
	REP(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
		mp[{a, b}] = i;
		mp[{b, a}] = i;
	}
	priority_queue<T, vector<T>, greater<T>> pq;
	pq.push({0, 0, -1});
	vector<ll> dist(n, INF64);
	dist[0] = 0;
	vector<int> ans;
	while(!pq.empty()){
		T t = pq.top(); pq.pop();
		ll d = get<0>(t);
		int v = get<1>(t);
		int p = get<2>(t);
		if(dist[v] < d) continue;
		if(p != -1) ans.push_back(p + 1);
		for(Edge e : G[v]){
			int u = e.to;
			int c = e.cost;
			if(chmin(dist[u], d + c)){
				pq.push({dist[u], u, mp[{v, u}]});
			}
		}
	}
	for(int v : ans){
		cout << v << ' ';
	}
	cout << endl;
}