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
	string s;
	cin >> n >> s;
	int ans = 0;
	REP(x, 10){
		REP(y, 10){
			REP(z, 10){
				bool x_ok = false;
				bool y_ok = false;
				bool z_ok = false;
				REP(i, n){
					if(!x_ok){
						if(s[i] == x + '0'){
							x_ok = true;
						}
					}
					else if(!y_ok){
						if(s[i] == y + '0'){
							y_ok = true;
						}
					}
					else if(!z_ok){
						if(s[i] == z + '0'){
							z_ok = true;
						}
					}
				}
				if(z_ok){
					++ans;
				}
			}
		}
	}
	cout << ans << endl;
}