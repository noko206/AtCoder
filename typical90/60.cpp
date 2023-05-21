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
template<class T> void debug(const vector<T> &a) { for(int i = 0; i < a.size(); ++i) cout << a[i] << ' '; cout << "\n"; }

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) {
		cin >> a[i];
	}
	vector<int> dp1(n), dp2(n), lis1(n, INF32), lis2(n, INF32);
	REP(i, n){
		auto it = lower_bound(ALL(lis1), a[i]);
		*it = a[i];
		dp1[i] = it - lis1.begin() + 1;
	}
	for(int i = n - 1; i >= 0; --i){
		auto it = lower_bound(ALL(lis2), a[i]);
		*it = a[i];
		dp2[n - (i + 1)] = it - lis2.begin() + 1;
	}
	int ans = 0;
	REP(i, n){
		chmax(ans, dp1[i] + dp2[n - (i + 1)] - 1);
	}
	cout << ans << endl;
}