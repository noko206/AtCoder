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

int main(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<pair<int, int>> math(n), eng(n), all(n);
	map<int, bool> is_pass;
	REP(i, n){
		int a;
		cin >> a;
		math[i] = {a, -i};
		all[i] = {a, -i};
	}
	REP(i, n){
		int b;
		cin >> b;
		eng[i] = {b, -i};
		all[i].first += b;
	}
	sort(ALLR(math));
	sort(ALLR(eng));
	sort(ALLR(all));
	int cnt = 0;
	for(auto v : math){
		if(cnt == x) break;
		int idx = -v.second;
		if(is_pass.find(idx) == is_pass.end()){
			is_pass[idx] = true;
			++cnt;
		}
	}
	cnt = 0;
	for(auto v : eng){
		if(cnt == y) break;
		int idx = -v.second;
		if(is_pass.find(idx) == is_pass.end()){
			is_pass[idx] = true;
			++cnt;
		}
	}
	cnt = 0;
	for(auto v : all){
		if(cnt == z) break;
		int idx = -v.second;
		if(is_pass.find(idx) == is_pass.end()){
			is_pass[idx] = true;
			++cnt;
		}
	}
	for(auto p : is_pass){
		cout << p.first + 1 << endl;
	}
}