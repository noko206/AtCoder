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

char f(int flg){
	if(flg == 0) return 'x';
	if(flg == 1) return '.';
	if(flg == 2) return 'o';
}

int main(){
	int a, b;
	cin >> a >> b;
	vector<int> flg(11, 0);
	REP(i, a){
		int p;
		cin >> p;
		if(p == 0) p = 10;
		flg[p] = 1;
	}
	REP(i, b){
		int q;
		cin >> q;
		if(q == 0) q = 10;
		flg[q] = 2;
	}
	printf("%c %c %c %c\n", f(flg[7]), f(flg[8]), f(flg[9]), f(flg[10]));
	printf(" %c %c %c\n", f(flg[4]), f(flg[5]), f(flg[6]));
	printf("  %c %c\n", f(flg[2]), f(flg[3]));
	printf("   %c\n", f(flg[1]));
}