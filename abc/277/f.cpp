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

bool check(vector<vector<int>> a, int h, int w){
	bool is_ok = true;
	int left = 0;
	int right = 1;
	while(right < w){
		bool left_large = false;
		bool confirm = false;
		REP(i, h){
			if(a[i][left] == a[i][right]) continue;
			if(a[i][left] == 0 || a[i][right] == 0) continue;
			if(!confirm){
				if(a[i][left] > a[i][right]) left_large = true;
				else left_large = false;
				confirm = true;
			}
			else{
				if(left_large && a[i][left] < a[i][right]) is_ok = false;
				if(!left_large && a[i][left] > a[i][right]) is_ok = false;
			}
		}
		if(!confirm){
			left = right;
			++right;
		}
		else{
			if(left_large){
				++right;
			}
			else{
				left = right;
				++right;
			}
		}
	}
	return is_ok;
}

int main(){
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w)), b(w, vector<int> (h));
	REP(i, h){
		REP(j, w){
			cin >> a[i][j];
		}
	}
	REP(i, h){
		REP(j, w){
			b[j][i] = a[i][j];
		}
	}
	auto f = [](auto const a, auto const b) {
		return a[0] > b[0];
	};
	sort(ALL(a), f);
	sort(ALL(b), f);
	if(check(a, h, w) && check(b, w, h)){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	// REP(i, h){
	// 	REP(j, w){
	// 		cout << a[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// REP(i, w){
	// 	REP(j, h){
	// 		cout << b[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
}