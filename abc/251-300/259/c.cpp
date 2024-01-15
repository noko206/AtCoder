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
	string s, t;
	cin >> s >> t;
	vector<pair<char, int>> x, y;
	x = run_length_encode(s);
	y = run_length_encode(t);
	if(x.size() != y.size()){
		cout << "No" << endl;
		return 0;
	}
	REP(i, x.size()){
		if(x[i].first != y[i].first){
			cout << "No" << endl;
			return 0;
		}
		if(x[i].second == 1 && x[i].second != y[i].second){
			cout << "No" << endl;
			return 0;
		}
		if(x[i].second > y[i].second){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}