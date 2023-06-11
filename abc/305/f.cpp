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
	vector<bool> visited(n, false);
	bool is_ok = false;
	auto dfs = [&](auto &dfs, int v = 0) -> void {
		if(is_ok) return;
		if(v == n - 1){
			string ok;
			cin >> ok;
			is_ok = true;
			return;
		}
		int k;
		cin >> k;
		REP(i, k){
			int u;
			cin >> u;
			if(to[v].size() < k){
				--u;
				to[v].push_back(u);
			}
		}
		visited[v] = true;
		for(int u : to[v]){
			if(visited[u]) continue;
			cout << u + 1 << endl;
			dfs(dfs, u);
			if(is_ok) return;
			cout << v + 1 << endl;
			int tmp_k;
			cin >> tmp_k;
			REP(i, tmp_k){
				int tmp_v;
				cin >> tmp_v;
			}
		}
	};
	dfs(dfs);
}