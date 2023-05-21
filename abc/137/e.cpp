#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(int i=int(a);i>=int(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

struct Edge{
	ll from;
	ll to;
	ll cost;
};

using Edges = vector<Edge>;

bool bellman_ford(const Edges &Es, int V, int s, vector<long long> &dis) {
	dis.resize(V, INF64);
	dis[s] = 0;
	int cnt = 0;
	while (cnt < V) {
		bool end = true;
		for (auto e : Es) {
			if (dis[e.from] != INF64 && dis[e.from] + e.cost < dis[e.to]) {
				dis[e.to] = dis[e.from] + e.cost;
				end = false;
			}
		}
		if (end) break;
		cnt++;
	}
	return (cnt == V);
}

int main(){
	int n, m, p;
	cin >> n >> m >> p;
	Edges edges(m);
	REP(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		edges[i] = {a, b, p - c};
	}
	vector<ll> dist;
	if(bellman_ford(edges, n, 0, dist)){
		output(dist);
		output(-1);
	}
	else{
		output(max(-dist[n - 1], 0LL));
	}
}