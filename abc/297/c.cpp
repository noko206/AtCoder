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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	REP(i, h) cin >> s[i];
	REP(i, h){
		REP(j, w - 1){
			if(s[i][j] == 'T' && s[i][j + 1] == 'T'){
				s[i][j] = 'P';
				s[i][j + 1] = 'C';
				++j;
			}
		}
	}
	REP(i, h){
		cout << s[i] << endl;
	}
}