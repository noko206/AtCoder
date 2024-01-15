#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int MOD1000000007 = 1000000007;
const int MOD998244353 = 998244353;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int n;
	ll p, q, r;
	cin >> n >> p >> q >> r;
	vector<int> a(n);
	vector<ll> tot(n + 1, 0);
	REP(i, n) {
		cin >> a[i];
		tot[i + 1] = tot[i] + a[i];
	}
	REP(x, n){
		int y = n;
		int ng = 0;
		while(y - ng != 1){
			int mid = (y + ng) / 2;
			if(tot[mid] - tot[x] >= p){
				y = mid;
			}
			else{
				ng = mid;
			}
		}
		//cout << "p: " << tot[y] - tot[x] << endl;
		if(tot[y] - tot[x] != p) continue;

		int z = n;
		ng = 0;
		while(z - ng != 1){
			int mid = (z + ng) / 2;
			if(tot[mid] - tot[y] >= q){
				z = mid;
			}
			else{
				ng = mid;
			}
		}
		//cout << "r: " << tot[z] - tot[y] << endl;
		if(tot[z] - tot[y] != q) continue;

		int w = n;
		ng = 0;
		while(w - ng != 1){
			int mid = (w + ng) / 2;
			if(tot[mid] - tot[z] >= r){
				w = mid;
			}
			else{
				ng = mid;
			}
		}
		//cout << "q: " << tot[w] - tot[z] << endl;
		if(tot[w] - tot[z] != r) continue;

		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}