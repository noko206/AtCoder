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
	int h, w;
	cin >> h >> w;
	vector<pair<int, int>> p(2);
	bool flg = false;
	REP(i, h){
		string s;
		cin >> s;
		REP(j, w){
			if(s[j] == 'o'){
				if(flg){
					p[1] = {i, j};
				}
				else{
					p[0] = {i, j};
					flg = true;
				}
			}
		}
	}
	cout << abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second) << endl;
}