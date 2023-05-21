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

int dfs(int k, vector<int> a){
	if(k < 0) return 0;
	vector<int> s, t;
	REP(i, a.size()){
		if(a[i] & (1 << k)) s.push_back(a[i]);
		else t.push_back(a[i]);
	}
	if(s.size() == 0) return dfs(k - 1, t);
	if(t.size() == 0) return dfs(k - 1, s);
	return min(dfs(k - 1, s), dfs(k - 1, t)) | (1 << k);
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	cout << dfs(29, a) << endl;
}