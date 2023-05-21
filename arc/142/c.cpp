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
	int n;
	cin >> n;
	vector<int> dist(n);
	dist[0] = 0;
	vector<vector<int>> to(n);
	REP(i, n){
		REP(j, i + 1, n){
			if(i + j >= 2){
				cout << '?' << ' ' << i + 1 << ' ' << j + 1 << endl;
				int d;
				cin >> d;
				if(i == 0) dist[j] = d;
				if(d == 1) {
					to[i].push_back(j);
					to[j].push_back(i);
				}
			}
		}
	}
	REP(i, n) {
		if(i == 1) continue;
		vector<vector<int>> G = to;
		G[1].push_back(i);
		G[i].push_back(1);
		queue<int> q;
		q.push(0);
		vector<bool> visited(n, false);
		bool is_ok = true;
		while(!q.empty()){
			int v = q.front(); q.pop();
			visited[v] = true;
			for(int u : to[v]){
				if(v == u) continue;
				if(visited[u]) continue;
				//cout << v << " -> " << u << endl;
				if(dist[u] != dist[v] + 1 && u != 1){
					//cout << "dist" << endl;
					is_ok = false;
					break;
				}
				if(u == 1){
					dist[u] = dist[v] + 1;
				}
				q.push(u);
			}
			if(!is_ok) break;
		}
		if(is_ok){
			cout << '!' << ' ' << dist[1] << endl;
			return 0;
		}
	}
	assert(true);
	return 0;
}