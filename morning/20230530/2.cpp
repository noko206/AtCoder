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

// 1:a_win, 0:drow, -1:a_lose
int sente_win(char a, char b){
	int a_num, b_num;
	if(a == 'G') a_num = 0;
	if(a == 'C') a_num = 1;
	if(a == 'P') a_num = 2;
	if(b == 'G') b_num = 0;
	if(b == 'C') b_num = 1;
	if(b == 'P') b_num = 2;

	if(a_num == b_num) return 0;
	if((a_num + 1) % 3 == b_num) return 1;
	return -1;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(2 * n);
	REP(i, 2 * n) cin >> a[i];
	vector<vector<pair<int, int>>> rank(m + 1);
	REP(i, 2 * n){
		rank[0].push_back({0, i});
	}
	REP(i, m){
		REP(j, n){
			auto p = rank[i][2 * j];
			auto q = rank[i][2 * j + 1];
			int res = sente_win(a[p.second][i], a[q.second][i]);
			if(res == -1) --q.first;
			if(res == 1) --p.first;
			rank[i + 1].push_back(p);
			rank[i + 1].push_back(q);
			// if(i == 0) cout << res << endl;
		}
		sort(ALL(rank[i + 1]));
	}
	vector<int> ans(2 * n);
	REP(i, 2 * n){
		ans[i] = rank[m][i].second + 1;
	}
	output(ans);
	// REP(i, m + 1){
	// 	vector<int> ans(2 * n);
	// 	REP(j, 2 * n){
	// 		ans[rank[i][j].second] = j + 1;
	// 	}
	// 	output(ans);
	// }
	// output("---");
	// REP(i, 2 * n){
	// 	cout << rank[1][i].first << ' ' << rank[1][i].second << endl;
	// }
}