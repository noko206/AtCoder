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
	vector<int> u(n - 1), v(n - 1), w(n - 1);
	REP(i, n - 1) cin >> u[i] >> v[i] >> w[i], --u[i], --v[i];
	vector<vector<int>> to(n);
	unordered_map<pair<int, int>, int>> mp;
	REP(i, n - 1){
		to[u[i]].push_back(v[i]);
		to[v[i]].push_back(u[i]);
		mp[{u[i], v[i]}] = w[i];
		mp[{v[i], u[i]}] = w[i];
	}
	vector<bool> visited(n, false);
	vector<int> id(n);
	vector<int> euler_tour;
	int cnt = 0;
	auto dfs = [&](int v = 0, int p = -1) -> void {
		if(!visited[v]){
			id[v] = cnt;
			++cnt;
		}
		visited[v] = true;
		euler_tour.push_back(v);
		if(to[v].size() == 1) return;
		for(auto u : to[v]){
			if(u == p) continue;
			dfs(u, v);
		}
		euler_tour.push_back(v);
	};
	setgree<int, op, e> seg(euler_tour.size());
	fenwick_tree<ll> fw(euler_tour.size());
	ll tot = 0;
	REP(i, euler_tour.size()){
		seg.set(i, euler_tour[i]);
		if(i != 0){
			ll tmp = mp[{euler_tour[i], euler_tour[i - 1]}];
			if(id[euler_tour[i - 1]] > id[euler_tour[i]]) tmp *= -1;
			tot += tmp;
			fw.add(i, tot);
		}
	}
	int q;
	cin >> q;
	vector<ll> ans;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int i, w;
			cin >> i >> w;
			--i;
			fw.
		}
	}
}