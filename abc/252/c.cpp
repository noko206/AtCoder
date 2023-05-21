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
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	REP(i, n){
		cin >> s[i];
	}
	int ans = INF;
	REP(num, 10){
		vector<bool> is_stopped(n, false);
		int t = -1;
		int cnt = 0;
		while(cnt < n){
			++t;
			REP(i, n){
				if(is_stopped[i]) continue;
				if(s[i][t % 10] - '0' == num){
					is_stopped[i] = true;
					++cnt;
					break;
				}
			}
		}
		chmin(ans, t);
	}
	cout << ans << endl;
}