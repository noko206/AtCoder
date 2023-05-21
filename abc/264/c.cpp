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
	int ha, wa;
	cin >> ha >> wa;
	vector<vector<int>> a(ha, vector<int>(wa));
	REP(i, ha){
		REP(j, wa){
			cin >> a[i][j];
		}
	}
	int hb, wb;
	cin >> hb >> wb;
	vector<vector<int>> b(hb, vector<int>(wb));
	REP(i, hb){
		REP(j, wb){
			cin >> b[i][j];
		}
	}
	REP(i, 1 << ha){
		if(ha - __builtin_popcount(i) != hb) continue;
		REP(j, 1 << wa){
			if(wa - __builtin_popcount(j) != wb) continue;
			unordered_map<int, int> mpy;
			unordered_map<int, int> mpx;
			int idx = 0;
			REP(y, ha){
				if(i & (1 << y)) continue;
				mpy[idx] = y;
				++idx;
			}
			idx = 0;
			REP(x, wa){
				if(j & (1 << x)) continue;
				mpx[idx] = x;
				++idx;
			}

			bool is_ok = true;
			REP(y, hb){
				REP(x, wb){
					if(a[mpy[y]][mpx[x]] != b[y][x]) is_ok = false;
				}
			}
			if(is_ok){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}