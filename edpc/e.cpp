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
	int n, w;
	cin >> n >> w;
	vector<int> weight(n), value(n);
	REP(i, n) cin >> weight[i] >> value[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(100005, INF64));
	dp[0][0] = 0;
	REP(i, n){
		REP(j, 100005){
			if(j - value[i] >= 0){
				chmin(dp[i + 1][j], dp[i][j - value[i]] + weight[i]);
			}
			chmin(dp[i + 1][j], dp[i][j]);
		}
	}
	ll ans = 0;
	REP(i, 100005){
		if(dp[n][i] <= w){
			chmax(ans, (ll)i);
		}
	}
	cout << ans << endl;
}