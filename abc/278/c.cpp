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
	int n, q;
	cin >> n >> q;
	map<pair<int, int>, bool> mp;
	vector<bool> ans;
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			mp[{a, b}] = true;
		}
		if(t == 2){
			mp.erase({a, b});
		}
		if(t == 3){
			if(mp.find({a, b}) != mp.end() && mp.find({b, a}) != mp.end()){
				ans.push_back(true);
			}
			else{
				ans.push_back(false);
			}
		}
	}
	for(bool is_ok : ans){
		if(is_ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}