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
	string s;
	cin >> s;
	if(s[0] == '1'){
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int>> row(7);
	row[0] = {6};
	row[1] = {3};
	row[2] = {7, 1};
	row[3] = {4, 0};
	row[4] = {8, 2};
	row[5] = {5};
	row[6] = {9};
	REP(i, 7){
		// jが小さい
		REP(j, i){
			if(abs(i - j) == 1) continue;
			bool is_up = false;
			for(int v : row[i]) if(s[v] == '1') is_up = true;
			if(!is_up) continue;
			is_up = false;
			for(int v : row[j]) if(s[v] == '1') is_up = true;
			if(!is_up) continue;

			REP(k, j + 1, i){
				bool is_ok = true;
				for(int v : row[k]){
					if(s[v] == '1') is_ok = false;
				}
				if(is_ok){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}