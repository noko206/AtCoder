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
	vector<int> h(3), w(3);
	REP(i, 3){
		cin >> h[i];
	}
	REP(i, 3){
		cin >> w[i];
	}
	ll ans = 0;
	REP(f11, 1, 31){
		REP(f12, 1, 31){
			REP(f21, 1, 31){
				REP(f22, 1, 31){
					int f13 = h[0] - (f11 + f12);
					int f23 = h[1] - (f21 + f22);
					int f31 = w[0] - (f11 + f21);
					int f32 = w[1] - (f12 + f22);
					int f33 = h[2] - (f31 + f32);
					if(f13 <= 0 || f23 <= 0 || f33 <= 0 || f31 <= 0 || f32 <= 0) continue;
					if(f33 == w[2] - (f13 + f23)) ++ans;
				}
			}
		}
	}
	cout << ans << endl;
}