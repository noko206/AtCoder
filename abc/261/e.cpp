#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1000000007;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int dp[200005][35][2];

int main(){
	int n, c;
	cin >> n >> c;
	vector<int> t(n), a(n);
	REP(i, n){
		cin >> t[i] >> a[i];
	}
	REP(i, 32){
		REP(j, 2){
			dp[0][i][j] = j;
		}
	}
	REP(i, n){
		REP(k, 2){
			int tmp = a[i];
			REP(j, 32){
				if(t[i] == 1){
					dp[i + 1][j][k] = dp[i][j][k] & (tmp % 2);
				}
				if(t[i] == 2){
					dp[i + 1][j][k] = dp[i][j][k] | (tmp % 2);
				}
				if(t[i] == 3){
					dp[i + 1][j][k] = dp[i][j][k] ^ (tmp % 2);
				}
				tmp /= 2;
			}
		}
	}
	int tmp = c;
	vector<int> ans(n);
	REP(i, n){
		string base2 = "";
		REP(j, 32){
			base2 += (char)(dp[i + 1][j][tmp % 2] + '0');
			tmp /= 2;
		}
		reverse(ALL(base2));
		//cout << base2 << endl;
		ll tot = 0;
		REP(i, base2.length()){
			tot *= 2;
			tot += (base2[i] - '0');
		}
		ans[i] = tot;
		tmp = tot;
	}
	REP(i, n){
		cout << ans[i] << endl;
	}
}