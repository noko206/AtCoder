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
	vector<ll> x(3);
	REP(i, 3) cin >> x[i];
	sort(ALLR(x));
	ll a, b, c;
	a = x[0];
	b = x[1];
	c = x[2];
	if(a > b + c){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 2 * a - b - c;
	x[0] = a - ans;
	x[1] = b + c - a;
	x[2] = b + c - a;
	if(ans % 2 == 0){
		if((b + c) % 2 == 1){
			++x[1];
		}
	}
	else{
		if((b + c) % 2 == 0){
			++x[1];
		}
	}
	if(x[0] == x[1] && x[1] == x[2]){
		ans += x[0];
	}
	else if(x[1] == x[2]){
		ans += 2;
		ans += x[1] - 1;
	}
	else{
		++ans;
		ans += x[2];
	}
	cout << ans << endl;
}