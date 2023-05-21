#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int MOD1000000007 = 1000000007;
const int MOD998244353 = 998244353;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	REP(i, n){
		cin >> s[i];
	}
	unordered_map<string, bool> mp;
	REP(i, m){
		cin >> t[i];
		mp[t[i]] = true;
	}
	vector<int> p(n);
	REP(i, n){
		p[i] = i;
	}
	int mx = 0;
	REP(i, n){
		mx += s[i].length();
	}
	if(n - 1 + mx > 16){
		cout << -1 << endl;
		return 0;
	}
	string ans = "";
	vector<int> max_arr(n, 0);
	REP(i, 1, n){
		max_arr[n - i - 1] = s[n - i].length();
		if(i != 0){
			max_arr[n - i - 1] += max_arr[n - i];
		}
	}
	auto dfs = [&](auto &dfs, int v, string str) -> void {
		str += s[p[v]];
		if(str.length() > 16) return;
		if(v == n - 1){
			if(str.length() >= 3 && mp.find(str) == mp.end()){
				ans = str;
				return;
			}
		}
		else{
			int str_len = str.length();
			REP(i, 16 - (str_len + max_arr[v])){
				str += '_';
				dfs(dfs, v + 1, str);
			}
		}
	};
	do{
		dfs(dfs, 0, "");
		if(ans != "") break;
	}while(next_permutation(ALL(p)));
	if(ans == "") cout << -1 << endl;
	else cout << ans << endl;
}