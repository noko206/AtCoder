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
	ll base = 0;
	int idx = 0;
	REP(i, n) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	vector<unordered_map<int, ll>> mp(q + 5);
	REP(i, n) {
		mp[idx][i] = a[i];
	}
	vector<ll> ans;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			base = x;
			++idx;
		}
		if(t == 2){
			int i, x;
			cin >> i >> x;
			--i;
			mp[idx][i] += x;
		}
		if(t == 3){
			int i;
			cin >> i;
			--i;
			if(mp[idx].find(i) == mp[idx].end()){
				ans.push_back(base);
			}
			else{
				ans.push_back(mp[idx][i] + base);
			}
		}
	}
	for(ll v : ans) cout << v << endl;
}