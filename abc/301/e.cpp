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

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int dp[1 << 18][18];

int main(){
	int h, w, t;
	cin >> h >> w >> t;
	vector<string> a(h);
	vector<pair<int, int>> pos;
	REP(i, h) cin >> a[i];
	REP(i, h) REP(j, w) if(a[i][j] == 'o') pos.push_back({i, j});
	REP(i, h) REP(j, w) if(a[i][j] == 'S') pos.push_back({i, j});
	REP(i, h) REP(j, w) if(a[i][j] == 'G') pos.push_back({i, j});
	map<pair<int, int>, int> id;
	int n = (int)pos.size();
	REP(i, n){
		id[{pos[i].first, pos[i].second}] = i;
	}
	vector<vector<int>> d(n, vector<int>(n, INF32));
	REP(i, n){
		vector<vector<int>> dist(h, vector<int>(w, INF32));
		dist[pos[i].first][pos[i].second] = 0;
		queue<pair<int, int>> q;
		q.push({pos[i].first, pos[i].second});
		d[i][i] = 0;
		while(!q.empty()){
			auto p = q.front(); q.pop();
			int y = p.first;
			int x = p.second;
			REP(j, 4){
				int ny = y + dy[j];
				int nx = x + dx[j];
				if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if(a[ny][nx] == '#') continue;
				if(chmin(dist[ny][nx], dist[y][x] + 1)){
					q.push({ny, nx});
					if(a[ny][nx] != '.'){
						chmin(d[i][id[{ny, nx}]], dist[ny][nx]);
					}
				}
			}
		}
	}
	if(d[n - 2][n - 1] > t){
		output(-1);
		return 0;
	}
	int ans = 0;
	REP(i, 1 << (n - 2)) REP(j, n - 2) dp[i][j] = INF32;
	REP(i, n - 2){
		int dist = d[n - 2][i] + d[i][n - 1];
		if(dist <= t){
			dp[1 << i][i] = dist;
			ans = 1;
		}
	}
	REP(i, 1, 1 << (n - 2)){
		// 最後に訪れたところ
		REP(j, n - 2){
			if(!(i & (1 << j))) continue;
			// 次に行くところ
			REP(k, n - 2){
				if(i & (1 << k)) continue;
				int dist = dp[i][j] - d[j][n - 1] + d[j][k] + d[k][n - 1];
				if(dist > t) continue;
				chmin(dp[i | (1 << k)][k], dist);
				chmax(ans, __builtin_popcount(i | (1 << k)));
				// output(i, j, k, dist, ans, '|', dp[i][j], d[j][n - 1], d[j][k], d[k][n - 1]);
			}
		}
	}
	output(ans);
	// REP(i, n){
	// 	output(d[i]);
	// }
}