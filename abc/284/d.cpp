#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	int t;
	cin >> t;
	vector<bool> sieve(3000005, true);
	REP(i, 2, 3000000){
		if(!sieve[i]) continue;
		for(int j = i + i; j < 3000000; j += i){
			sieve[j] = false;
		}
	}
	vector<ll> prime;
	REP(i, 2, 3000000){
		if(sieve[i]){
			prime.push_back(i);
		}
	}
	vector<pair<ll, ll>> ans(t);
	REP(i, t){
		ll n;
		cin >> n;
		bool is_ok = false;
		for(ll p : prime){
			if((n % (p * p)) == 0){
				ans[i] = {p, n / (p * p)};
				is_ok = true;
				break;
			}
		}
		if(is_ok) continue;
		for(ll q : prime){
			if(n % q == 0) {
				ans[i] = {sqrt(n / q), q};
				break;
			}
		}
	}
	REP(i, t) cout << ans[i].first << ' ' << ans[i].second << endl;
}