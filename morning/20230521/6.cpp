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
	int to;
	int from;
	int cost;
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dist(n, vector<ll>(n, INF64));
	vector<Edge> e(m);
	REP(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		dist[a][b] = c;
		dist[b][a] = c;
		e[i] = {a, b, c};
	}
	REP(i, n){
		dist[i][i] = 0;
	}
	REP(k, n){
		REP(i, n){
			REP(j, n){
				chmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	REP(i, m){
		int a = e[i].to;
		int b = e[i].from;
		int c = e[i].cost;
		if(dist[a][b] < c){
			++ans;
			continue;
		}
		bool is_deleted = false;
		REP(j, n){
			if(j == a || j == b) continue;
			if(dist[a][j] + dist[j][b] == c){
				is_deleted = true;
			}
		}
		if(is_deleted) ++ans;
	}
	output(ans);
}