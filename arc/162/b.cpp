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
	vector<int> p(n);
	REP(i, n) cin >> p[i], --p[i];
	if(n == 2){
		if(p[0] == 0 && p[1] == 1){
			output("Yes");
			output(0);
		} else {
			output("No");
		}
		return 0;
	}
	vector<pair<int, int>> ans;
	REP(i, n){
		if(p[i] == i) continue;
		vector<int> q;
		REP(j, i + 1, n){
			if(j == n - 1){
				int a = p[n - 1], b = p[n - 3], c = p[n - 2];
				p[n - 3] = a;
				p[n - 2] = b;
				p[n - 1] = c;
				ans.push_back({n - 2, n - 2});
				--i;
				break;
			}
			if(p[j] == i){
				REP(k, i){
					q.push_back(p[k]);
				}
				q.push_back(p[j]);
				q.push_back(p[j + 1]);
				REP(k, i, n){
					if(k == j || k == j + 1) continue;
					q.push_back(p[k]);
				}
				p = q;
				ans.push_back({j + 1, i});
				break;
			}
		}
	}
	bool is_ok = true;
	REP(i, n) if(p[i] != i) is_ok = false;
	if(!is_ok || (int)ans.size() > 2000){
		output("No");
		return 0;
	}
	int m = (int)ans.size();
	output("Yes");
	output(m);
	REP(i, m){
		output(ans[i].first, ans[i].second);
	}
}