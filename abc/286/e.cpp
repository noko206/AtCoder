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
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<string> s(n);
	REP(i, n) cin >> s[i];
	vector<vector<ll>> dist(n, vector<ll>(n, INF64));
	vector<vector<ll>> value(n, vector<ll>(n, 0));
	REP(i, n){
		dist[i][i] = 0;
		value[i][i] = a[i];
	}
	REP(i, n){
		REP(j, n){
			if(s[i][j] == 'Y'){
				dist[i][j] = 1;
				value[i][j] = a[i] + a[j];
			}
		}
	}
	REP(k, n){
		REP(i, n){
			REP(j, n){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					value[i][j] = value[i][k] + value[k][j] - a[k];
				}
				else if(dist[i][j] == dist[i][k] + dist[k][j]){
					chmax(value[i][j], value[i][k] + value[k][j] - a[k]);
				}
			}
		}
	}
	int q;
	cin >> q;
	REP(i, q){
		int u, v;
		cin >> u >> v;
		--u; --v;
		if(dist[u][v] == INF64){
			cout << "Impossible" << endl;
		}
		else{
			cout << dist[u][v] << ' ' << value[u][v] << endl;
		}
	}
}