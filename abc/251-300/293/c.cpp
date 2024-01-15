#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

const int dy[] = {1, 0};
const int dx[] = {0, 1};

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	REP(i, h) REP(j, w) cin >> a[i][j];
	unordered_set<int> st;
	int ans = 0;
	auto dfs = [&](auto &dfs, int y, int x) -> void {
		if(st.find(a[y][x]) != st.end()) return;
		if(y == h - 1 && x == w - 1) {
			++ans;
			return;
		}
		st.insert(a[y][x]);
		REP(i, 2){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			dfs(dfs, ny, nx);
		}
		st.erase(a[y][x]);
	};
	dfs(dfs, 0, 0);
	cout << ans << endl;
}