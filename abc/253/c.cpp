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
	map<int, int> mp;
	vector<int> ans;
	REP(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			++mp[x];
		}
		if(t == 2){
			int x, c;
			cin >> x >> c;
			if(mp.find(x) != mp.end()) {
				REP(j, c){
					if(mp[x] == 0) break;
					--mp[x];
				}
				if(mp[x] == 0){
					mp.erase(x);
				}
			}
		}
		if(t == 3){
			auto begin = mp.begin();
			auto end = mp.end();
			--end;
			ans.push_back((*end).first - (*begin).first);
		}
	}
	for (int v : ans){
		cout << v << endl;
	}
}