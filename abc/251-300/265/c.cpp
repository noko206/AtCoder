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
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	REP(i, h) cin >> g[i];
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	int ansY, ansX;
	auto dfs = [&](auto &dfs, int y = 0, int x = 0) -> bool {
		if(visited[y][x]) return false;
		visited[y][x] = true;
		ansY = y; ansX = x;
		if(g[y][x] == 'U') --y;
		else if(g[y][x] == 'D') ++y;
		else if(g[y][x] == 'L') --x;
		else if(g[y][x] == 'R') ++x;
		if(x < 0 || y < 0 || x >= w || y >= h) return true;
		return dfs(dfs, y, x);
	};
	if(dfs(dfs)) cout << ansY + 1 << ' ' << ansX + 1 << endl;
	else cout << -1 << endl;
}