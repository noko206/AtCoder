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

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> to(n);
	REP(i, m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	int k;
	cin >> k;
	vector<int> p(k), d(k);
	REP(i, k){
		cin >> p[i] >> d[i];
		--p[i];
	}
	vector<vector<int>> dist(n, vector<int>(n, INF32));
	REP(i, n){
		queue<int> q;
		q.push(i);
		dist[i][i] = 0;
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int u : to[v]){
				if(chmin(dist[i][u], dist[i][v] + 1)){
					q.push(u);
				}
			}
		}
	}
	vector<bool> is_white(n, false);
	REP(i, k){
		REP(j, n){
			if(dist[p[i]][j] < d[i]){
				is_white[j] = true;
			}
		}
	}
	bool is_ok = true;
	REP(i, k){
		bool ok = false;
		REP(j, n){
			if(dist[p[i]][j] == d[i] && !is_white[j]){
				ok = true;
			}
		}
		if(!ok) is_ok = false;
	}
	YesNo(is_ok);
	if(is_ok){
		REP(i, n){
			if(is_white[i]) cout << 0;
			else cout << 1;
		}
		cout << endl;
	}
}