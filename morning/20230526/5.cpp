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
	int n;
	cin >> n;
	vector<vector<int>> to(n);
	REP(i, n - 1){
		int u, v;
		cin >> u >> v;
		--u, --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	// 部分木のサイズ
	vector<int> cnt(n);
	auto dfs1 = [&](auto &dfs1, int v = 0, int p = -1) -> int {
		int sum = 1;
		for(int u : to[v]){
			if(u == p) continue;
			sum += dfs1(dfs1, u, v);
		}
		return cnt[v] = sum;
	};
	dfs1(dfs1);
	vector<ll> ans(n);
	// 根の答えだけ先に求める
	auto dfs2 = [&](auto &dfs2, int v = 0, int p = -1, int d = 0) -> void {
		ans[0] += d;
		for(int u : to[v]){
			if(u == p) continue;
			dfs2(dfs2, u, v, d + 1);
		}
	};
	dfs2(dfs2);
	// 全頂点に対して答えを求める
	auto dfs3 = [&](auto &dfs3, int v = 0, int p = -1) -> void {
		for(int u : to[v]){
			if(u == p) continue;
			ans[u] = ans[v] + (n - cnt[u]) - cnt[u];
			dfs3(dfs3, u, v);
		}
	};
	dfs3(dfs3);
	output(ans);
}