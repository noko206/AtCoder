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

vector<string> conv(vector<string> x){
	int min_h = INF32, min_w = INF32, max_h = -1, max_w = -1;
	REP(i, (int)x.size()){
		REP(j, x[0].length()){
			if(x[i][j] == '#'){
				chmin(min_h, i);
				chmin(min_w, j);
				chmax(max_h, i);
				chmax(max_w, j);
			}
		}
	}
	vector<string> ans;
	REP(i, (int)x.size()){
		string tmp = "";
		REP(j, x[0].length()){
			if(i < min_h) continue;
			if(j < min_w) continue;
			if(i > max_h) continue;
			if(j > max_w) continue;
			tmp += x[i][j];
		}
		ans.push_back(tmp);
	}
	return ans;
}

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

	a = conv(a);
	b = conv(b);
	x = conv(x);

	REP(ai, 10 - (int)a.size() + 1){
		REP(aj, 10 - a[0].length() + 1){
			REP(bi, 10 - (int)b.size() + 1){
				REP(bj, 10 - b[0].length() + 1){
					vector<string> tmp(10, "..........");
					REP(i, (int)a.size()){
						REP(j, a[0].length()){
							if(a[i][j] == '#'){
								tmp[i + ai][j + aj] = '#';
							}
						}
					}
					REP(i, (int)b.size()){
						REP(j, b[0].length()){
							if(b[i][j] == '#'){
								tmp[i + bi][j + bj] = '#';
							}
						}
					}
					REP(xi, 10 - (int)x.size() + 1){
						REP(xj, 10 - x[0].length() + 1){
							bool is_ok = true;
							REP(i, 10){
								REP(j, 10){
									if(i - xi < 0 || j - xj < 0 || i - xi >= (int)x.size() || j - xj >= x[0].length()){
										if(tmp[i][j] == '#'){
											is_ok = false;
											break;
										}
									} else if(tmp[i][j] != x[i - xi][j - xj]){
										is_ok = false;
										break;
									}
								}
								if(!is_ok) break;
							}
							if(is_ok){
								output("Yes");
								return 0;
							}
						}
					}
				}
			}
		}
	}
	output("No");
}