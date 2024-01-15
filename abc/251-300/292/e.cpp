#include <bits/stdc++.h>
using namespace std;

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

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> to(n);
	REP(i, m){
		int u, v;
		cin >> u >> v;
		--u; --v;
		to[u].push_back(v);
	}
	int ans = 0;
	REP(i, n){
		queue<int> q;
		q.push(i);
		vector<int> dist(n, INF32);
		dist[i] = 0;
		while(!q.empty()){
			int v = q.front(); q.pop();
			if(dist[v] == 2){
				dist[v] = 1;
				++ans;
			}
			for(int u : to[v]){
				if(chmin(dist[u], dist[v] + 1)){
					q.push(u);
				}
			}
		}
	}
	cout << ans << endl;
}