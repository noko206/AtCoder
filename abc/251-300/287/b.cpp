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
	vector<string> s(n), t(m);
	REP(i, n) cin >> s[i];
	REP(i, m) cin >> t[i];
	int ans = 0;
	REP(i, n){
		bool is_ok = false;
		REP(j, m){
			if(s[i][3] == t[j][0] && s[i][4] == t[j][1] && s[i][5] == t[j][2]) is_ok = true;
		}
		if(is_ok) ++ans;
	}
	cout << ans << endl;
}