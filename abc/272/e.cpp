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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<vector<int>> num(m);
	REP(i, n){
		if(a[i] > n) continue;
		int l = 1;
		if(a[i] < 0) l = (-a[i] + i) / (i + 1);
		int r = min(m, (n - a[i]) / (i + 1));
		REP(j, l, r + 1){
			num[j - 1].push_back(a[i] + (i + 1) * j);
		}
	}
	vector<int> ans;
	REP(i, m){
		vector<bool> exists(m + 1, false);
		for(int v : num[i]){
			exists[v] = true;
		}
		REP(j, m + 1){

		}
	}
}