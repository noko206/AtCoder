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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	REP(i, n) REP(j, n) cin >> a[i][j];
	vector<vector<int>> dist(n, vector<int>(n, INF32));
	REP(i, n) REP(j, n) if(a[i][j] == 1) dist[i][j] = 1;
	REP(k, n){
		REP(i, n){
			REP(j, n){
				chmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int q;
	cin >> q;
	vector<int> ans;
	while(q--){
		ll s, t;
		cin >> s >> t;
		--s; --t;
		s %= n;
		t %= n;
		ans.push_back(dist[s][t] == INF32 ? -1 : dist[s][t]);
	}
	for(auto v : ans) cout << v << endl;
}