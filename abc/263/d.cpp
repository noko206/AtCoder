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
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	vector<ll> sum(n + 1);
	sum[0] = 0;
	REP(i, n){
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	vector<ll> tot(n + 1);
	tot[n] = 0;
	ll mn = 0;
	int idx = n;
	vector<int> to(n + 1);
	to[n] = n;
	REP(i, n){
		tot[n - i - 1] = tot[n - i] + r - a[n - i - 1];
		if(chmin(mn, tot[n - i - 1])){
			idx = n - i - 1;
		}
		to[n - i - 1] = idx;
	}

	// メイン
	ll ans = INF64;
	REP(i, -1, n){
		chmin(ans, (ll)(i + 1) * l + (ll)(n - to[i + 1]) * r + sum[to[i + 1]] - sum[i + 1]);
		//cout << (ll)(i + 1) * l + (ll)(n - to[i + 1]) * r + sum[to[i]] - sum[i + 1] << endl;
	}
	cout << ans << endl;
}