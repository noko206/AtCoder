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

bool check(int h, int m){
	int a = h / 10;
	int b = h % 10;
	int c = m / 10;
	int d = m % 10;

	int nh = 10 * a + c;
	int nm = 10 * b + d;

	if (0 <= nh && nh < 24 && 0 <= nm && nm < 60) return true;
	else return false;
}

int main(){
	int h, m;
	cin >> h >> m;
	int hour = h;
	int minute = m;
	while(true){
		while(true){
			if(check(hour, minute)){
				cout << hour << ' ' << minute;
				return 0;
			}
			++minute;
			minute %= 60;
			if(minute == 0) break;
		}
		++hour;
		hour %= 24;
	}
}