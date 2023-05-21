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
	ll k;
	cin >> k;
	unordered_map<ll, ll> mp;
	for(ll i = 2; i * i <= k; ++i){
		while(k % i == 0){
			k /= i;
			++mp[i];
		}
	}
	if(k != 1) ++mp[k];
	ll ans = 1;
	for(pair<ll, ll> p : mp){

		ll d = p.first;
		ll cnt = p.second;
		ll mx = 0;
		for(ll i = d; cnt > 0; i += d){
			ll tmp = i;
			while(tmp % d == 0){
				tmp /= d;
				--cnt;
			}
			mx = i;
		}
		chmax(ans, mx);
	}
	cout << ans << endl;
}