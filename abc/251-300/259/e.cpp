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
	vector<vector<int>> p(n), e(n);
	REP(i, n){
		int m;
		cin >> m;
		REP(j, m){
			int _p, _e;
			cin >> _p >> _e;
			p[i].push_back(_p);
			e[i].push_back(_e);
		}
	}
	map<int, pair<int, int>> mp;
	REP(i, n){
		int m = p[i].size();
		REP(j, m){
			if(mp.find(p[i][j]) == mp.end()){
				mp[p[i][j]] = make_pair(e[i][j], 1);
			}
			else if(mp[p[i][j]].first < e[i][j]){
				mp[p[i][j]].first = e[i][j];
				mp[p[i][j]].second = 1;
			}
			else if(mp[p[i][j]].first == e[i][j]){
				++mp[p[i][j]].second;
			}
		}
	}
	int ans = 0;
	REP(i, n){
		int m = p[i].size();
		bool is_ok = false;
		REP(j, m){
			if(mp[p[i][j]].first == e[i][j] && mp[p[i][j]].second == 1){
				is_ok = true;
			}
		}
		if(is_ok) ++ans;
	}
	if(ans < n) ++ans;
	cout << ans << endl;
}