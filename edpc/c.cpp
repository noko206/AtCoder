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
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	REP(i, n) REP(j, 3) cin >> a[i][j];
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));
	REP(i, n){
		REP(j, 3){
			REP(k, 3){
				if(j != k){
					chmax(dp[i + 1][j], dp[i][k] + a[i][k]);
				}
			}
		}
	}
	cout << *max_element(ALL(dp[n])) << endl;
}