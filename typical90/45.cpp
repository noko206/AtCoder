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
	vector<ll> x(n), y(n);
	REP(i, n) cin >> x[i] >> y[i];
	vector<ll> d(1 << n, 0);
	REP(bit, 1 << n){
		vector<int> index;
		REP(i, n){
			if(bit & (1 << i)) index.push_back(i);
		}
		int m = index.size();
		REP(i, m){
			REP(j, i){
				int i1 = index[i];
				int i2 = index[j];
				chmax(d[bit], (x[i1] - x[i2]) * (x[i1] - x[i2]) + (y[i1] - y[i2]) * (y[i1] - y[i2]));
			}
		}
	}
	vector<vector<ll>> dp(1 << n, vector<ll>(k + 1, 8 * INF64));
	dp[0][0] = 0;
	REP(bit, 1 << n){
		REP(cnt, 1, k + 1){
			int b = bit;
			while(b > 0){
				chmin(dp[bit][cnt], max(dp[bit - b][cnt - 1], d[b]));
				b = (b - 1) & bit;
			}
		}
	}
	cout << dp[(1 << n) - 1][k] << endl;
}