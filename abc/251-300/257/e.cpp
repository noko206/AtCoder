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

ll dp[1000005];

int main(){
	int n;
	cin >> n;
	vector<int> c(9);
	int mi = INF32;
	REP(i, 9){
		cin >> c[i];
		chmin(mi, c[i]);
	}
	int k = n / mi;
	string ans = "";
	while(true){
		bool is_ok = false;
		for(int i = 8; i >= 0; --i){
			if(n >= c[i] && (n - c[i]) / mi == k - 1){
				ans += (char)(i + '1');
				--k;
				n -= c[i];
				is_ok = true;
				break;
			}
		}
		if(!is_ok){
			break;
		}
	}
	cout << ans << endl;
}