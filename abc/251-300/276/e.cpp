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

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	REP(i, h) cin >> c[i];
	int si, sj;
	REP(i, h){
		REP(j, w){
			if(c[i][j] == 'S'){
				si = i;
				sj = j;
			}
		}
	}
	queue<P> p;
	REP(k, 4){
		int fi = si + dy[k];
		int fj = sj + dx[k];
		if(fi < 0 || fj < 0 || fi >= h || fj >= w) continue;
		if(c[fi][fj] == '#') continue;
		p.push({1, {fi, fj}});
		vector<vector<int>> dist(h, vector<int>(w, INF32));
		dist[fi][fj] = 1;
		while(!p.empty()){
			P q = p.front(); p.pop();
			int d = q.first;
			int y = q.second.first;
			int x = q.second.second;
			REP(i, 4){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if(c[ny][nx] == '#') continue;
				if(c[ny][nx] == 'S' && d + 1 < 4) continue;
				if(chmin(dist[ny][nx], d + 1)){
					p.push({d + 1, {ny, nx}});
				}
			}
		}
		if(dist[si][sj] != INF32){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}