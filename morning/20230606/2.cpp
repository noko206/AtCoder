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

const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<pair<int, int>> list1, list2;
	REP(i, 8) list1.push_back({x1 + dx[i], y1 + dy[i]});
	REP(i, 8) list2.push_back({x2 + dx[i], y2 + dy[i]});
	REP(i, 8){
		REP(j, 8){
			int a = list1[i].first;
			int b = list1[i].second;
			int c = list2[j].first;
			int d = list2[j].second;
			if(a == c && b == d){
				output("Yes");
				return 0;
			}
		}
	}
	output("No");
}