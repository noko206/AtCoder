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

using P = pair<int, pair<int, int>>;

int main(){
	int n, m;
	cin >> n >> m;
	// 前処理
	unordered_map<int, int> my_sqrt;
	for(int i = 0; i * i <= m; ++i) {
		my_sqrt[i * i] = i;
	}
	vector<pair<int, int>> tmp;
	for(int i = 0; i * i <= m; ++i) {
		if(my_sqrt.find(m - (i * i)) != my_sqrt.end()){
			tmp.push_back({i, my_sqrt[m - (i * i)]});
		}
	}
	vector<pair<int, int>> to;
	for(pair<int, int> p : tmp){
		to.push_back({p.first, p.second});
		to.push_back({p.first, -p.second});
		to.push_back({-p.first, p.second});
		to.push_back({-p.first, -p.second});
	}

	// ダイクストラ
	vector<vector<int>> dist(n, vector<int>(n, INF32));
	dist[0][0] = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	while(!pq.empty()){
		P p = pq.top(); pq.pop();
		int cnt = p.first;
		int x = p.second.first;
		int y = p.second.second;
		//cout << x << ' ' << y << endl;
		if(dist[y][x] < cnt) continue;
		for(pair<int, int> next : to){
			int nx = x + next.first;
			int ny = y + next.second;
			if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if(dist[ny][nx] <= dist[y][x] + 1) continue;
			dist[ny][nx] = dist[y][x] + 1;
			pq.push(make_pair(dist[ny][nx], make_pair(nx, ny)));
		}
	}
	REP(i, n){
		REP(j, n){
			if(dist[i][j] == INF32) cout << -1 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}