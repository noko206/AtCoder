#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	vector<int> c(n + m);
	REP(i, n){
		cin >> a[i];
		c[i] = a[i];
	}
	REP(i, m){
		cin >> b[i];
		c[i + n] = b[i];
	}
	sort(ALL(c));
	map<int, int> mp;
	REP(i, n + m){
		mp[c[i]] = i + 1;
	}
	REP(i, n){
		cout << mp[a[i]] << ' ';
	}
	cout << endl;
	REP(i, m){
		cout << mp[b[i]] << ' ';
	}
	cout << endl;
}