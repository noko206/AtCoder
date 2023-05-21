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

using Graph = vector<vector<int>>;
vector<vector<ll>> cnt;

int main(){
	int n, m;
	cin >> n >> m;
	Graph G(n);
	REP(i, m){
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cnt.resize(n);
	REP(i, n){
		cnt[i].resize(4, 0);
	}
	REP(i, n){
		unordered_map<int, bool> mp;
		mp[i] = true;
		queue<pair<int, int>> que;
		que.push({i, 0});
		while(!que.empty()){
			pair<int, int> p = que.front();
			que.pop();
			int v = p.first;
			int d = p.second;
			cnt[i][d] += v + 1;
			if(d == 3) continue;
			for(int u : G[v]){
				if(mp.find(u) != mp.end()) continue;
				que.push({u, d + 1});
				mp[u] = true;
			}
		}
		REP(j, 3){
			cnt[i][j + 1] += cnt[i][j];
		}
	}
	int q;
	cin >> q;
	vector<int> ans(q);
	REP(i, q){
		int x, k;
		cin >> x >> k;
		--x;
		ans[i] = cnt[x][k];
	}
	REP(i, q){
		cout << ans[i] << endl;
	}
}