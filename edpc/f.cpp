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
	vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
	REP(i, s.length()){
		REP(j, t.length()){
			if(s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1); // s[i](t[j])を使う場合
			chmax(dp[i + 1][j + 1], dp[i][j + 1]); // t[j]を使わない場合
			chmax(dp[i + 1][j + 1], dp[i + 1][j]); // s[i]を使わない場合
		}
	}
	string ans = "";
	int i = s.length(), j = t.length();
	while(i > 0 && j > 0){
		// (i-1,j)->(i,j)の更新だった場合
		if(dp[i][j] == dp[i - 1][j]){
			--i;
		}
		// (i,j-1)->(i,j)の更新だった場合
		else if(dp[i][j] == dp[i][j - 1]){
			--j;
		}
		// (i-1,j-1)->(i,j)の更新だった場合
		else{
			ans += s[i - 1]; // s[i-1](t[j-1])を使っているので文字を足す
			--i; --j;
		}
	}
	// 逆順になっているので元に戻す
	reverse(ALL(ans));
	cout << ans << endl;
}