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

ll f_reverse(ll x){
	ll ans = 0;
	while(x > 0){
		ans *= 10;
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int f_count(ll x, ll n){
	int ans = 0;
	while(x <= n){
		++ans;
		x *= 10;
	}
	return ans;
}

int main(){
	ll n, k;
	cin >> n >> k;
	if(k > f_reverse(k) || k > f_reverse(f_reverse(k))){
		cout << 0 << endl;
		return 0;
	}
	ll ans = f_count(k, n) + f_count(f_reverse(k), n);
	if(k == f_reverse(k)) ans /= 2;
	cout << ans << endl;
}