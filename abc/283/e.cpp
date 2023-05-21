#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int MOD1000000007 = 1000000007;
const int MOD998244353 = 998244353;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	REP(i, h) REP(j, w) cin >> a[i][j];

	vector<vector<bool>> yoko_ok(h, vector<bool>(w, false));

	// 横方向
	REP(i, h){
		REP(j, w){
			if(j > 0 && a[i][j - 1] != a[i][j]) yoko_ok[i][j] = true;
			if(j < w - 1 && a[i][j] != a[i][j + 1]) yoko_ok[i][j] = true;
		}
	}

	// 縦方向
	REP(i, h){
		REP(j, w){
			
		}
	}
}