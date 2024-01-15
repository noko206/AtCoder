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
	string s, t;
	cin >> s >> t;
	if(s.length() < t.length()){
		cout << "No" << endl;
		return 0;
	}
	bool is_ok = false;
	REP(i, 150){
		if(i + t.length() > s.length()) break;
		if(t == s.substr(i, t.length())) is_ok = true;
	}
	cout << (is_ok ? "Yes" : "No") << endl;
}