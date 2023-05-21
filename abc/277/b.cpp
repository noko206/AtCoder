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

const char one[] = {'H', 'D', 'C', 'S'};
const char two[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	REP(i, n) cin >> s[i];
	bool is_ok = true;
	REP(i, n){
		bool one_ok = false;
		REP(j, 4){
			if(s[i][0] == one[j]) one_ok = true;
		}
		bool two_ok = false;
		REP(j, 13){
			if(s[i][1] == two[j]) two_ok = true;
		}
		if(!one_ok || !two_ok) is_ok = false;
	}
	REP(i, n){
		REP(j, i){
			if(s[i] == s[j]) is_ok = false;
		}
	}
	if(is_ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}