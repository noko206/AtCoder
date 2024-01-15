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
	int w = 1000000;
	int n = 300;
	srand(time(NULL));
	while(true){
		vector<int> a(n);
		a[0] = 1;
		a[1] = 2;
		a[2] = 4;
		a[3] = 8;
		map<int, int> test;
		test[1] = 1;
		test[2] = 1;
		test[4] = 1;
		test[8] = 1;
		REP(i, 4, n){
			while(true){
				int r = rand() % (w + 1);
				if (test.find(r) == test.end()) {
					a[i] = r;
					test[r] = 1;
					break;
				}
			}
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
		if (mp.size() == w) {
			sort(ALL(a));
			REP(i, n) {
				cout << a[i] << ',';
			}
			cout << endl;
			return 0;
		}
	}
}