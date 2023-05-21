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
	int ok_cnt = 0;
	int n = s.length();
	int m = t.length();
	REP(i, m) {
		if(s[i + (n - m)] == t[i]) ++ok_cnt;
		else if(s[i + (n - m)] == '?') ++ok_cnt;
		else if(t[i] == '?') ++ok_cnt;
	}
	vector<bool> ans(m + 1, false);
	if(ok_cnt == m) ans[0] = true;
	REP(i, m){
		if(s[i + (n - m)] == t[i]) --ok_cnt;
		else if(s[i + (n - m)] == '?') --ok_cnt;
		else if(t[i] == '?') --ok_cnt;

		if(s[i] == t[i]) ++ok_cnt;
		else if(s[i] == '?') ++ok_cnt;
		else if(t[i] == '?') ++ok_cnt;

		if(ok_cnt == m) ans[i + 1] = true;
	}
	REP(i, m + 1){
		if(ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}