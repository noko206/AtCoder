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

int dp[100005][5];

int main(){
	int n, k, r, s, p;
	string t;
	cin >> n >> k >> r >> s >> p >> t;
	REP(i, n){
		if(i - k < 0){
			if(t[i] == 'r') dp[i][0] = p;
			if(t[i] == 's') dp[i][1] = r;
			if(t[i] == 'p') dp[i][2] = s;
			continue;
		}
		if(t[i] == 'r'){
			chmax(dp[i][0], dp[i - k][1] + p);
			chmax(dp[i][0], dp[i - k][2] + p);
			chmax(dp[i][1], dp[i - k][0]);
			chmax(dp[i][1], dp[i - k][2]);
			chmax(dp[i][2], dp[i - k][0]);
			chmax(dp[i][2], dp[i - k][1]);
		}
		if(t[i] == 's'){
			chmax(dp[i][0], dp[i - k][1]);
			chmax(dp[i][0], dp[i - k][2]);
			chmax(dp[i][1], dp[i - k][0] + r);
			chmax(dp[i][1], dp[i - k][2] + r);
			chmax(dp[i][2], dp[i - k][0]);
			chmax(dp[i][2], dp[i - k][1]);
		}
		if(t[i] == 'p'){
			chmax(dp[i][0], dp[i - k][1]);
			chmax(dp[i][0], dp[i - k][2]);
			chmax(dp[i][1], dp[i - k][0]);
			chmax(dp[i][1], dp[i - k][2]);
			chmax(dp[i][2], dp[i - k][0] + s);
			chmax(dp[i][2], dp[i - k][1] + s);
		}
	}
	int ans = 0;
	REP(i, n - k, n){
		int tmp = 0;
		REP(j, 3){
			chmax(tmp, dp[i][j]);
		}
		ans += tmp;
	}
	cout << ans << endl;
}