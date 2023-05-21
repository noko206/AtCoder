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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	vector<ll> b = a;
	sort(ALL(b));
	ll idx = 0;
	ll sub = 0;
	ll cnt = 0;
	while(true){
		if(idx == n) break;
		if(b[idx] - sub <= 0){
			++idx;
			continue;
		}
		ll tmp = (b[idx] - sub) * (n - idx);
		if(cnt + tmp >= k){
			ll ok = 0;
			ll ng = b[idx] - sub + 1;
			while(ng - ok != 1){
				ll mid = (ok + ng) / 2;
				if(cnt + mid * (n - idx) <= k){
					ok = mid;
				}
				else{
					ng = mid;
				}
			}
			sub += ok;
			cnt += ok * (n - idx);
			break;
		}
		cnt += tmp;
		sub = b[idx];
		++idx;
	}
	REP(i, n){
		if(cnt == k) break;
		if(a[i] - sub > 0){
			--a[i];
			++cnt;
		}
	}
	REP(i, n){
		a[i] -= sub;
		if(a[i] < 0) a[i] = 0;
	}
	REP(i, n){
		cout << a[i] << ' ';
	}
	cout << endl;
}