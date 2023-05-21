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
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> masu(n, -1);
	REP(i, k){
		int a;
		cin >> a;
		masu[a - 1] = i;
	}
	REP(i, q){
		int l;
		cin >> l;
		int cnt = 0;
		int j = 0;
		for(j = 0; j < n; ++j){
			if(masu[j] != -1){
				++cnt;
			}
			if(cnt == l) break;
		}
		if(j == n - 1) continue;
		if(masu[j + 1] != -1) continue;
		masu[j + 1] = masu[j];
		masu[j] = -1;
	}
	REP(i, n){
		if(masu[i] != -1){
			cout << i + 1 << ' ';
		}
	}
	cout << endl;
}