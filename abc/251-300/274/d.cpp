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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> ax, ay;
	REP(i, n) {
		int a;
		cin >> a;
		if(i % 2 == 0) ax.push_back(a);
		else ay.push_back(a);
	}
	vector<unordered_set<int>> dpx(ax.size() + 1), dpy(ay.size() + 1);
	dpx[0].insert(0);
	REP(i, ax.size()){
		int a = ax[i];
		for(int pre : dpx[i]){
			dpx[i + 1].insert(pre + a);
			if(i != 0) dpx[i + 1].insert(pre - a);
		}
	}
	dpy[0].insert(0);
	REP(i, ay.size()){
		int a = ay[i];
		for(int pre : dpy[i]){
			dpy[i + 1].insert(pre + a);
			dpy[i + 1].insert(pre - a);
		}
	}
	bool is_ok_x = false;
	bool is_ok_y = false;
	for(int a : dpx[ax.size()]) {
		// cout << a << ' ';
		if(a == x) is_ok_x = true;
	}
	// cout << endl;
	for(int a : dpy[ay.size()]) {
		// cout << a << ' ';
		if(a == y) is_ok_y = true;
	}
	// cout << endl;
	if(is_ok_x && is_ok_y){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}