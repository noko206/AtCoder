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

const int dy[] = {-1, 1, 1, -1};
const int dx[] = {1, 1, -1, -1};

int main(){
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	REP(i, h) cin >> c[i];
	dsu uf(h * w);
	REP(i, h){
		REP(j, w){
			if(c[i][j] == '#'){
				REP(k, 4){
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
					if(c[ny][nx] == '.') continue;
					if(!uf.same(i * w + j, ny * w + nx)){
						uf.merge(i * w + j, ny * w + nx);
					}
				}
			}
		}
	}
	vector<vector<int>> g = uf.groups();
	vector<int> ans(min(h, w) + 1, 0);
	for(auto v : g){
		++ans[v.size() / 4];
	}
	REP(i, min(h, w)) output(ans[i + 1]);
}