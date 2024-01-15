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
	string s;
	cin >> s;
	vector<bool> used(26, false);
	bool is_ok = true;
	vector<int> to(s.length(), -1);
	vector<int> begin_pos;
	vector<vector<int>> tot(s.length() + 1, vector<int>(26, 0));
	int begin_cnt = 0;
	int end_cnt = 0;
	REP(i, s.length()){
		if(s[i] == '(') {
			++begin_cnt;
			begin_pos.push_back(i);
		}
		else if(s[i] == ')') {
			++end_cnt;
			to[i] = begin_pos[begin_cnt - end_cnt];
		}
		else{
			++tot[i + 1][s[i] - 'a'];
		}
		REP(j, 26){
			tot[i + 1][j] += tot[i][j];
		}
	}

	REP(i, s.length()){
		if('a' <= s[i] && s[i] <= 'z'){
			if(used[s[i] - 'a']){
				is_ok = false;
			}
			else{
				used[s[i] - 'a'] = true;
			}
		}
		if(s[i] == '('){
			continue;
		}
		if(s[i] == ')'){
			REP(j, 26){
				if(tot[i + 1][j] - tot[to[i] + 1][j] > 0){
					used[j] = false;
				}
			}
		}
	}
	if(is_ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}