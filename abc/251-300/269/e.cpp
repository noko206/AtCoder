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
	cin >> n;
	// 縦
	int l = 1;
	int r = n;
	while(r != l){
		int mid = (r + l) / 2;
		// l~midの間にあるルークの個数を聞く
		printf("? %d %d %d %d\n", 1, n, l, mid);
		int t;
		cin >> t;
		if(mid - l + 1 == t){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}

	int y = l;

	// 横
	int u = 1;
	int d = n;
	while(u != d){
		int mid = (u + d) / 2;
		// u~midの間にあるルークの個数を聞く
		printf("? %d %d %d %d\n", u, mid, 1, n);
		int t;
		cin >> t;
		if(mid - u + 1 == t){
			u = mid + 1;
		}
		else{
			d = mid;
		}
	}

	int x = u;

	printf("! %d %d\n", x, y);
}