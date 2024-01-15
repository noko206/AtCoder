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
	vector<string> a(n);
	REP(i, n){
		cin >> a[i];
	}
	bool is_mujun = false;
	REP(i, n){
		REP(j, n){
			if(a[i][j] == 'W' && a[j][i] != 'L'){
				is_mujun = true;
			}
			if(a[i][j] == 'L' && a[j][i] != 'W'){
				is_mujun = true;
			}
			if(a[i][j] == 'D' && a[j][i] != 'D'){
				is_mujun = true;
			}
		}
	}
	if(is_mujun){
		cout << "incorrect" << endl;
	}
	else{
		cout << "correct" << endl;
	}
}