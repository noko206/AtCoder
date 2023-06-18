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

bool solve(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> to(n);
	REP(i, 1, n){
		int p;
		cin >> p;
		--p;
		to[p].push_back(i);
	}
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	REP(i, n){
		set<int> st;
		int emp_cnt = 0;
		bool is_ok = true;
		auto dfs = [&](auto &dfs, int v) -> void {
			if(a[v] == k) is_ok = false;
			else if(a[v] == -1) ++emp_cnt;
			else if(a[v] < k) st.insert(a[v]);
			for(auto u : to[v]) dfs(dfs, u);
		};
		dfs(dfs, i);
		if(!is_ok || emp_cnt >= 2) continue;
		if((int)st.size() == k || (emp_cnt == 1 && (int)st.size() == k - 1)){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	REP(i, t){
		output(solve() ? "Alice" : "Bob");
	}
}