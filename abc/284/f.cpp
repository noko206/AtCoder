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
	int n;
	cin >> n;
	string t;
	cin >> t;
	int m = 2 * n;
	string a = "";
	string b = "";
	vector<bool> same(n + 1, false);
	same[0] = true;
	REP(i, n - 1){
		a += t[i];
		b = t[m - (n - i) - 1] + b;
		if(a == b) same[i + 1] = true;
	}
	REP(i, m){
		if(t[i] != t[m - 1]) continue;
		bool is_ok = true;
		REP(j, 1, n - i){
			if(t[i + j] != t[m - 1 - j]){
				is_ok = false;
				break;
			}
		}
		if(!is_ok) continue;
		if(same[i]){
			cout << t.substr(0, i) + t.substr(m - (n - i)) << endl;
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}