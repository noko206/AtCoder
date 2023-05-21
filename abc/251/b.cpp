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
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	REP(i, n){
		cin >> a[i];
	}
	unordered_map<int, int> mp;
	REP(i, n){
		if (a[i] > w) continue;
		++mp[a[i]];
		REP(j, n){
			if (i == j) continue;
			if (a[i] + a[j] > w) continue;
			++mp[a[i] + a[j]];
			REP(k, n){
				if (i == j || j == k || k == i) continue;
				if (a[i] + a[j] + a[k] > w) continue;
				++mp[a[i] + a[j] + a[k]];
			}
		}
	}
	cout << mp.size() << endl;
}