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
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	int m;
	cin >> m;
	unordered_map<int, bool> mp;
	REP(i, m){
		int b;
		cin >> b;
		mp[b] = true;
	}
	int x;
	cin >> x;
	vector<bool> dp(x + 1, false);
	dp[0] = true;
	REP(i, x){
		if(!dp[i]) continue;
		REP(j, n){
			if(mp.find(i + a[j]) != mp.end()) continue;
			if(i + a[j] > x) continue;
			dp[i + a[j]] = true;
		}
	}
	if(dp[x]) cout << "Yes" << endl;
	else cout << "No" << endl;
}