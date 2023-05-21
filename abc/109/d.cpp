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
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	REP(i, h) REP(j, w) cin >> a[i][j];
	vector<vector<int>> ans;
	REP(i, h){
		REP(j, w - 1){
			if(a[i][j] % 2 == 1){
				--a[i][j];
				++a[i][j + 1];
				ans.push_back({i + 1, j + 1, i + 1, j + 2});
			}
		}
	}
	REP(i, h - 1){
		if(a[i][w - 1] % 2 == 1){
			--a[i][w - 1];
			++a[i + 1][w - 1];
			ans.push_back({i + 1, w, i + 2, w});
		}
	}
	cout << ans.size() << endl;
	for(auto v : ans){
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << endl;
	}
}