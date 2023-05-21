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

int main(){
	int n, q, x;
	cin >> n >> q >> x;
	vector<int> w(n);
	REP(i, n){
		cin >> w[i];
	}
	map<int, ll> mp;
	int idx = 0;
	while(mp.find(idx) == mp.end()){
		int now = idx;
		ll tot = 0;
		while(tot < (ll)x){
			tot += w[now];
			now = (now + 1) % n;
		}
		mp[idx] = tot;
		idx = now;
	}
	if(idx != 0){
		
	}
	vector<ll> ans(q);
	REP(i, q){
		ll k;
		cin >> k;

	}
}