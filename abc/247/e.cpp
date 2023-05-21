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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	REP(i, n){
		cin >> a[i];
	}
	auto calc = [&](vector<int> b) -> ll {
		int j = 0, cntX = 0, cntY = 0;
		ll res = 0;
		REP(i, b.size()){
			while(j < b.size() && (cntX == 0 || cntY == 0)){
				if(b[j] == x){
					++cntX;
				}
				if(b[j] == y){
					++cntY;
				}
				++j;
			}
			if(cntX > 0 && cntY > 0){
				res += b.size() - j + 1;
			}
			if(b[i] == x){
				--cntX;
			}
			if(b[i] == y){
				--cntY;
			}
		}
		return res;
	};
	ll ans = 0;
	vector<int> b;
	REP(i, n){
		if(a[i] > x || a[i] < y){
			ans += calc(b);
			b.clear();
		}
		else{
			b.push_back(a[i]);
		}
	}
	if(b.size() > 0){
		ans += calc(b);
	}
	cout << ans << endl;
}