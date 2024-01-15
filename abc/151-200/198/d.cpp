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
	string s[3];
	int cnt = 0;
	unordered_map<char, int> mp;
	REP(i, 3){
		cin >> s[i];
		for(char c : s[i]){
			if(mp.find(c) == mp.end()){
				mp[c] = cnt;
				++cnt;
			}
		}
	}
	if(cnt > 10){
		cout << "UNSOLVABLE" << endl;
		return 0;
	}
	vector<int> p(10);
	REP(i, 10){
		p[i] = i;
	}
	sort(ALL(p));
	auto f = [&](string t, vector<int> q) -> ll {
		if(q[mp[t[0]]] == 0) return -1;
		int n = t.length();
		ll ans = 0;
		REP(i, n){
			ans *= 10;
			ans += q[mp[t[i]]];
		}
		return ans;
	};
	do{
		ll x = f(s[0], p);
		ll y = f(s[1], p);
		ll z = f(s[2], p);
		if(x == -1 || y == -1 || z == -1) continue;
		if(x + y == z){
			cout << x << endl;
			cout << y << endl;
			cout << z << endl;
			return 0;
		}
	}while(next_permutation(ALL(p)));
	cout << "UNSOLVABLE" << endl;
}