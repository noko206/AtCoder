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
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	REP(i, n){
		int tmp;
		cin >> tmp;
		a[i] = {tmp, i};
	}
	sort(ALLR(a));
	set<int> st;
	REP(i, k){
		int b;
		cin >> b;
		--b;
		st.insert(b);
	}
	int ma = a[0].first;
	bool is_ok = false;
	REP(i, n){
		if (ma != a[i].first) {
			break;
		}
		if (st.find(a[i].second) != st.end()) {
			is_ok = true;
		}
	}
	if(is_ok){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}