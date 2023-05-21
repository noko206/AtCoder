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

double dist(ll a, ll b, ll c, ll d){
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
	int n, m;
	cin >> n >> m;
	int l = n + m;
	vector<ll> x(l), y(l);
	REP(i, l) cin >> x[i] >> y[i];
	// bitDP
	vector<vector<double>> dp(1 << l, vector<double>(l, (double)INF64));
	REP(i, (1 << l)){
		REP(j, l){
			// 行ったことがなければダメ
			if(!(i & (1 << j)) && i != 0) continue;
			REP(k, l){
				// 行ったことがあったらダメ
				if(i & (1 << k)) continue;
				int prex = (i == 0) ? 0 : x[j];
				int prey = (i == 0) ? 0 : y[j];
				int nowx = x[k];
				int nowy = y[k];
				// ブースト
				int ksk = pow(2, __builtin_popcount(i >> n));
				if (i == 0) chmin(dp[i | (1 << k)][k], dist(prex, prey, nowx, nowy) / (double)ksk);
				else chmin(dp[i | (1 << k)][k], dp[i][j] + dist(prex, prey, nowx, nowy) / (double)ksk);
			}
		}
	}
	double ans = (double)INF64;
	REP(i, (1 << l)){
		bool is_ok = true;
		REP(j, n){
			if(!(i & (1 << j))) is_ok = false;
		}
		if(is_ok){
			REP(j, n){
				int prex = x[j];
				int prey = y[j];
				int nowx = 0;
				int nowy = 0;
				// ブースト
				int ksk = pow(2, __builtin_popcount(i >> n));
				chmin(ans, dp[i][j] + dist(prex, prey, nowx, nowy) / (double)ksk);
				// cout << prex << ' ' << prey << endl;
				// cout << dp[i][j] << ' ' << dist(prex, prey, nowx, nowy) << ' ' << (double)ksk << endl;
			}
		}
	}
	printf("%.9f\n", ans);
	// cout << ans << endl;
	// REP(i, 1 << l){
	// 	REP(j, l){
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
}