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

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	REP(i, h){
		cin >> s[i];
	}
	map<pair<int, int>, vector<pair<int, int>>> G;
	REP(i, h){
		REP(j, w){
			if(j + 1 < w && s[i][j] != s[i][j + 1]){
				G[{i, j}].push_back({i, j + 1});
				G[{i, j + 1}].push_back({i, j});
			}
			if(i + 1 < h && s[i][j] != s[i + 1][j]){
				G[{i, j}].push_back({i + 1, j});
				G[{i + 1, j}].push_back({i, j});
			}
		}
	}
	vector<vector<bool>> seen(h, vector<bool>(w, false));
	int black = 0;
	int white = 0;
	ll ans = 0;
	auto dfs = [&](auto &dfs, int y, int x){
		if(seen[y][x]) return;
		seen[y][x] = true;
		if(s[y][x] == '#') ++black;
		else ++white;
		if(G.find({y, x}) == G.end()) return;
		for(pair<int, int> p : G[{y, x}]){
			dfs(dfs, p.first, p.second);
		}
	};
	REP(i, h){
		REP(j, w){
			if(seen[i][j]) continue;
			dfs(dfs, i, j);
			ans += (ll)black * white;
			black = 0;
			white = 0;
		}
	}
	cout << ans << endl;
}