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
	int n, m;
	cin >> n >> m;
	vector<int> s(n - 1);
	vector<int> x(m);
	vector<ll> sum(n);
	sum[0] = 0;
	REP(i, n - 1){
		cin >> s[i];
		sum[i + 1] = s[i] - sum[i];
	}
	REP(i, m){
		cin >> x[i];
	}
	map<ll, int> mp;
	REP(i, n){
		REP(j, m){
			ll c = x[j] - sum[i];
			if(i % 2 == 0) c *= -1;
			++mp[c];
		}
	}
	int ans = 0;
	for(pair<ll, int> p : mp){
		chmax(ans, p.second);
	}
	cout << ans << endl;
}