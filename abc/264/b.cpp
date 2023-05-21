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
	int r, c;
	cin >> r >> c;
	--r; --c;
	vector<string> s(15);
	s[0]  = "bbbbbbbbbbbbbbb";
	s[1]  = "bwwwwwwwwwwwwwb";
	s[2]  = "bwbbbbbbbbbbbwb";
	s[3]  = "bwbwwwwwwwwwbwb";
	s[4]  = "bwbwbbbbbbbwbwb";
	s[5]  = "bwbwbwwwwwbwbwb";
	s[6]  = "bwbwbwbbbwbwbwb";
	s[7]  = "bwbwbwbwbwbwbwb";
	s[8]  = "bwbwbwbbbwbwbwb";
	s[9]  = "bwbwbwwwwwbwbwb";
	s[10] = "bwbwbbbbbbbwbwb";
	s[11] = "bwbwwwwwwwwwbwb";
	s[12] = "bwbbbbbbbbbbbwb";
	s[13] = "bwwwwwwwwwwwwwb";
	s[14] = "bbbbbbbbbbbbbbb";

	if(s[r][c] == 'b') cout << "black" << endl;
	else cout << "white" << endl;
}