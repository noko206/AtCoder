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

bool dp[55][10005];

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	REP(i, n) cin >> a[i] >> b[i];
	dp[0][0] = true;
	REP(i, n){
		REP(j, x + 1){
			if(!dp[i][j]) continue;
			REP(k, b[i] + 1){
				if(j + a[i] * k <= x) dp[i + 1][j + a[i] * k] = true;
			}
		}
	}
	if(dp[n][x]) cout << "Yes" << endl;
	else cout << "No" << endl;
}