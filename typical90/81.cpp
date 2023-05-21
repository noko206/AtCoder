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

int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> tot(5001, vector<int>(5001, 0));
	REP(i, n){
		int a, b;
		cin >> a >> b;
		++tot[a][b];
	}
	REP(i, 5000){
		REP(j, 5000){
			tot[i + 1][j + 1] += tot[i + 1][j];
		}
	}
	REP(j, 5000){
		REP(i, 5000){
			tot[i + 1][j + 1] += tot[i][j + 1];
		}
	}
	int ans = 0;
	REP(a, 1, 5001){
		REP(b, 1, 5001){
			chmax(ans, tot[a][b] - tot[max(a - k - 1, 0)][b] - tot[a][max(b - k - 1, 0)] + tot[max(a - k - 1, 0)][max(b - k - 1, 0)]);
		}
	}
	cout << ans << endl;
}