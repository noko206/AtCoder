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
	int n;
	cin >> n;
	vector<int> v(n);
	REP(i, n){
		cin >> v[i];
	}
	vector<pair<int, int>> even(100001), odd(100001);
	REP(i, 100001){
		even[i] = {0, i};
		odd[i] = {0, i};
	}
	REP(i, n){
		if(i % 2 == 0){
			++even[v[i]].first;
		}
		else{
			++odd[v[i]].first;
		}
	}
	sort(ALLR(even));
	sort(ALLR(odd));
	int ans = 0;
	if(even[0].second == odd[0].second){
		if(even[1].first > odd[1].first){
			ans = n - even[1].first - odd[0].first;
		}
		else{
			ans = n - even[0].first - odd[1].first;
		}
	}
	else{
		ans = n - even[0].first - odd[0].first;
	}
	cout << ans << endl;
}