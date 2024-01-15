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
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int q;
	cin >> q;
	vector<int> ans;
	map<int, int> mp;
	priority_queue<int, vector<int>, greater<int>> mi;
	priority_queue<int> ma;
	REP(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			++mp[x];
			mi.push(x);
			ma.push(x);
		}
		if(t == 2){
			int x, c;
			cin >> x >> c;
			if(mp.find(x) != mp.end()){
				mp[x] = max(mp[x] - c, 0);
			}
		}
		if(t == 3){
			int _ma = ma.top();
			int _mi = mi.top();
			while(mp[_ma] == 0){
				_ma = ma.top();
				ma.pop();
			}
			while(mp[_mi] == 0){
				_mi = mi.top();
				mi.pop();
			}
			ans.push_back(_ma - _mi);
		}
	}
	for (int v : ans){
		cout << v << endl;
	}
}