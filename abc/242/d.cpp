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
	string s;
	cin >> s;
	int q;
	cin >> q;
	vector<char> ans(q);
	REP(i, q){
		ll t, k;
		cin >> t >> k;
		--k;
		int pos = 0;
		if(t <= 60){
			ll tmp = 1LL << t;
			pos = k / tmp;
			k %= tmp;
		}
		ll right = __builtin_popcountll(k);
		ll left = t - right;
		ll tot = left + right * 2 + (s[pos] - 'A');
		ans[i] = (tot % 3) + 'A';
	}
	REP(i, q){
		cout << ans[i] << endl;
	}
}