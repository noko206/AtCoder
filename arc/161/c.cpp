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

const black = 0;
const white = 1;

int main(){
	int t;
	cin >> t;
	vector<string> ans;
	while(t--){
		vector<vector<int>> to(n);
		REP(i, n){
			int a, b;
			cin >> a >> b;
			--a, --b;
			to[a].push_back(b);
			to[b].push_back(a);
		}
		string s;
		cin >> s;
		vector<vector<int>> cnt(n, vector<int>(2, 0));
		auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
			// 葉の場合 (rootが葉のときは考慮しない)
			if(v != 0 && (int)to[v].size() == 1){
				++cnt[p][s[v] == 'B' ? black : white];
				++cnt[v][s[p] == 'B' ? black : white];
			} else {
				int black_cnt = 0;
				int white_cnt = 0;
				for(int u : to[v]){
					if(u == p) continue;
					dfs(dfs, u, v);
					
				}
				if(v != 0 && (int)to[v].size() > 1){

				}
			}
		};
		dfs(dfs);
	}
	REP(i, ans.size()){
		if(ans[i] == "") output(-1);
		else output(ans[i]);
	}
}