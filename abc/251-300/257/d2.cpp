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
	vector<ll> x(n), y(n), p(n);
	REP(i, n){
		cin >> x[i] >> y[i] >> p[i];
	}
	ll ok = INF64;
	ll ng = -1;
	while(ok - ng != 1){
		ll mid = (ok + ng) / 2;
		vector<vector<ll>> dist(n, vector<ll>(n, 0));
		vector<vector<bool>> wf(n, vector<bool>(n, false));
		REP(i, n){
			REP(j, n){
				dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
				if(p[i] <= INF64 / max(mid, 1) && dist[i][j] > p[i] * mid) dist[i][j] = -1;
				else wf[i][j] = true;
			}
		}
		REP(k, n){
			REP(i, n){
				REP(j, n){
					if(wf[i][k] && wf[k][j]){
						wf[i][j] = true;
					}
				}
			}
		}
		bool good = false;
		REP(i, n){
			bool is_ok = true;
			REP(j, n){
				if(!wf[i][j]){
					is_ok = false;
				}
			}
			if(is_ok){
				good = true;
			}
		}
		if(good){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	cout << ok << endl;
}