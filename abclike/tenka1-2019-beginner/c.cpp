#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1000000007;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

vector<pair<char, int>> run_length_encode(string s) {
	int n = s.length();
	char t = -1;
	vector<pair<char, int>> a;
	int j = -1;
	for(int i = 0; i < n; ++i){
		if(t != s[i]){
			++j;
			t = s[i];
			a.push_back(make_pair(t, 1));
		}
		else{
			++a[j].second;
		}
	}
	return a;
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<char, int>> encode = run_length_encode(s);
	int ans = 0;
	for(pair<char, int> p : encode){
		if(p.first == '.') ans += p.second;
	}
	int tot = ans;
	REP(i, encode.size()){
		char c = encode[i].first;
		int cnt = encode[i].second;
		if(c == '.'){
			tot -= cnt;
		}
		else{
			tot += cnt;
		}
		chmin(ans, tot);
	}
	cout << ans << endl;
}