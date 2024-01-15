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
	int ha, wa;
	cin >> ha >> wa;
	vector<string> a(ha);
	REP(i, ha) cin >> a[i];
	int hb, wb;
	cin >> hb >> wb;
	vector<string> b(hb);
	REP(i, hb) cin >> b[i];
	int hx, wx;
	cin >> hx >> wx;
	vector<string> x(hx);
	REP(i, hx) cin >> x[i];

	int a_sum = 0, b_sum = 0;
	REP(i, ha){
		REP(j, wa){
			if(a[i][j] == '#') ++a_sum;
		}
	}
	REP(i, hb){
		REP(j, wb){
			if(b[i][j] == '#') ++b_sum;
		}
	}

	REP(ai, -15, 15){
		REP(aj, -15, 15){
			REP(bi, -15, 15){
				REP(bj, -15, 15){
					bool is_ok = true;
					int a_cnt = 0, b_cnt = 0;
					REP(i, hx){
						REP(j, wx){
							char c = '.';
							if(i + ai >= 0 && i + ai < ha && j + aj >= 0 && j + aj < wa){
								if(a[i + ai][j + aj] == '#'){
									c = '#';
									++a_cnt;
								}
							}
							if(i + bi >= 0 && i + bi < hb && j + bj >= 0 && j + bj < wb){
								if(b[i + bi][j + bj] == '#'){
									c = '#';
									++b_cnt;
								}
							}
							if(x[i][j] != c) is_ok = false;
						}
					}
					if(a_cnt != a_sum || b_cnt != b_sum){
						is_ok = false;
					}
					if(is_ok){
						output("Yes");
						return 0;
					}
				}
			}
		}
	}

	output("No");
}