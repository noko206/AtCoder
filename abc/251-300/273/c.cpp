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
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	sort(ALL(a));
	vector<int> ans(n, 0);
	vector<int> cnt(n + 1, 0);
	map<int, bool> mp;
	for(int i = n - 1; i >= 0; --i){
		mp[a[i]] = true;
		cnt[i] = mp.size();
	}
	REP(i, n){
		int ok = n;
		int ng = -1;
		while(ok - ng != 1){
			int mid = (ok + ng) / 2;
			if(a[mid] > a[i]){
				ok = mid;
			}
			else{
				ng = mid;
			}
		}
		++ans[cnt[ok]];
	}
	REP(i, n) cout << ans[i] << endl;
}