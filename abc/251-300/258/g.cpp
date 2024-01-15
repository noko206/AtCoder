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
	vector<string> a(n);
	REP(i, n){
		cin >> a[i];
	}
	vector<int> cnt(n, 0);
	REP(i, n){
		int tot = 0;
		REP(j, i + 1, n){
			if(a[i][j] == '1' && a[]) ++tot;
		}
		cnt[i] = tot;
	}
	vector<ll> comb(n, 0);
	comb[2] = 1;
	REP(i, 3, n){
		comb[i] = comb[i - 1] * i / (i - 2);
	}
	ll ans = 0;
	REP(i, n){
		ans += comb[cnt[i]];
	}
	cout << ans << endl;
}