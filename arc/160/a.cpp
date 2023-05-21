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

vector<int> naive(int n, int k, vector<int> a){
	// output("---");
	vector<vector<int>> ans;
	REP(l, n){
		REP(r, l, n){
			vector<int> tmp = a;
			reverse(tmp.begin() + l, tmp.begin() + r + 1);
			ans.push_back(tmp);
		}
	}
	sort(ALL(ans));
	// for(auto v : ans){
	// 	output(v);
	// }
	return ans[k - 1];
}

vector<int> solve(int n, int k, vector<int> a){
	int rank = 0;
	REP(i, n){
		int cnt = 0;
		REP(j, i, n){
			if(a[i] > a[j]) ++cnt;
		}
		if(rank + cnt >= k){
			int idx = 0;
			vector<pair<int, int>> v;
			REP(j, i, n){
				if(a[i] > a[j]) v.push_back({a[j], j});
			}
			sort(ALL(v));
			for(auto p : v){
				++rank;
				if(rank == k) idx = p.second;
			}
			reverse(a.begin() + i, a.begin() + idx + 1);
			return a;
		}
		rank += cnt;
		int middle = (n - i) * (n - i + 1) / 2 - (n - i - 1) + i;
		if(rank + middle < k){
			rank += middle;
			int idx = 0;
			vector<pair<int, int>> v;
			REP(j, i, n){
				if(a[i] < a[j]) v.push_back({a[j], j});
			}
			sort(ALL(v));
			for(auto p : v){
				++rank;
				if(rank == k) idx = p.second;
			}
			reverse(a.begin() + i, a.begin() + idx + 1);
			return a;
		}
	}
	return a;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	// output("---");
	// REP(i, n * (n + 1) / 2) output(naive(n, i + 1, a));
	// output("---");
	// REP(i, n * (n + 1) / 2) output(solve(n, i + 1, a));

	// REP(i, n * (n + 1) / 2){
	// 	if(naive(n, i + 1, a) != solve(n, i + 1, a)) output(i + 1);
	// }

	output(solve(n, k, a));
}