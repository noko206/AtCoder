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

double dp[305][305][305];

int main(){
	int n;
	cin >> n;
	int one = 0, two = 0, three = 0;
	REP(i, n){
		int a;
		cin >> a;
		if(a == 1) ++one;
		if(a == 2) ++two;
		if(a == 3) ++three;
	}
	memset(dp, -1, sizeof(dp));
	auto dfs = [&](auto &dfs, int i, int j, int k) -> double {
		if(i == 0 && j == 0 && k == 0) return 0.0;
		if(dp[i][j][k] >= 0) return dp[i][j][k]; // dp[i][j][k]!=-1 のようにdouble型でイコール判定してはいけない(戒め)

		double res = 0.0;
		if(i > 0) res += dfs(dfs, i - 1, j, k) * i;
		if(j > 0) res += dfs(dfs, i + 1, j - 1, k) * j;
		if(k > 0) res += dfs(dfs, i, j + 1, k - 1) * k;
		res += n;
		res /= (double)(i + j + k);

		return dp[i][j][k] = res;
	};
	double ans = dfs(dfs, one, two, three);
	cout << setprecision(12) << ans << endl;
}