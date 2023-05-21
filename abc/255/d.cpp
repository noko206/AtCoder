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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	REP(i, n){
		cin >> a[i];
	}
	sort(ALL(a));
	vector<ll> tot(n + 1);
	tot[0] = 0;
	REP(i, n){
		tot[i + 1] = tot[i] + a[i];
	}
	vector<ll> ans(q);
	REP(i, q){
		int x;
		cin >> x;
		int ok = -1;
		int ng = n;
		while(ng - ok != 1){
			int mid = (ok + ng) / 2;
			if(a[mid] < x){
				ok = mid;
			}
			else{
				ng = mid;
			}
		}
		if(ok == -1){
			ans[i] = tot[n] - ((ll)n * x);
		}
		else if(ok == n - 1){
			if(a[n - 1] <= x){
				ans[i] = ((ll)n * x) - tot[n];
			}
			else{
				ans[i] = ((ll)(n - 1) * x) - tot[n - 1] + a[n - 1] + x;
			}
		}
		else{
			ll tmp = (ll)(ok + 1) * x - tot[ok + 1];
			tmp += (tot[n] - tot[ok + 1]) - (ll)(n - ok - 1) * x;
			ans[i] = tmp;
		}
	}
	REP(i, q){
		cout << ans[i] << endl;
	}
}