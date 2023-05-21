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

int dp[55][3000];

int main(){
	int n;
	cin >> n;
	vector<int> w(n), b(n);
	REP(i, n) cin >> w[i];
	REP(i, n) cin >> b[i];
	REP(i, 51){
		REP(j, 2900){
			vector<bool> mex(3000, false);
			if(i >= 1){
				mex[dp[i - 1][j + i]] = true;
			}
			if(j >= 2){
				REP(k, 1, (j / 2) + 1){
					mex[dp[i][j - k]] = true;
				}
			}
			REP(k, 3000){
				if(!mex[k]) {
					dp[i][j] = k;
					break;
				}
			}
		}
	}
	int xor_sum = 0;
	REP(i, n){
		xor_sum ^= dp[w[i]][b[i]];
	}
	cout << (xor_sum == 0 ? "Second" : "First") << endl;
}