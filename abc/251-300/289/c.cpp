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
	vector<vector<int>> a(m);
	REP(i, m){
		int c;
		cin >> c;
		a[i].resize(c);
		REP(j, c) {
			cin >> a[i][j];
			--a[i][j];
		}
	}
	int ans = 0;
	REP(bit, 1 << m){
		vector<bool> exists(n, false);
		REP(i, m){
			if(bit & (1 << i)){
				for(int v : a[i]){
					exists[v] = true;
				}
			}
		}
		bool is_ok = true;
		REP(i, n){
			if(!exists[i]) is_ok = false;
		}
		if(is_ok) ++ans;
	}
	cout << ans << endl;
}