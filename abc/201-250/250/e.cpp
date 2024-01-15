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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	REP(i, n){
		cin >> a[i];
	}
	REP(i, n){
		cin >> b[i];
	}
	// 前処理①
	vector<int> cntA(n), cntB(n);
	set<int> setA, setB;
	REP(i, n){
		setA.insert(a[i]);
		setB.insert(b[i]);
		cntA[i] = setA.size();
		cntB[i] = setB.size();
	}
	// 前処理②
	vector<int> numA, numB;
	setA.clear();
	setB.clear();
	REP(i, n){
		if(setA.find(a[i]) == setA.end()){
			numA.push_back(a[i]);
			setA.insert(a[i]);
		}
		if(setB.find(b[i]) == setB.end()){
			numB.push_back(b[i]);
			setB.insert(b[i]);
		}
	}
	int m = min(numA.size(), numB.size()); // a,bどちらかの種類数を超えた場合は条件を満たさないのでmin
	vector<bool> check(n, false);
	set<int> st;
	REP(i, m){
		for(int v : {numA[i], numB[i]}){
			if(st.find(v) == st.end()){
				st.insert(v);
			}
			else{
				st.erase(v);
			}
		}
		if(st.size() == 0){
			check[i] = true;
		}
	}
	// クエリの処理
	int q;
	cin >> q;
	vector<bool> ans;
	while(q--){
		int x, y;
		cin >> x >> y;
		--x; --y; // 0-indexed
		if(cntA[x] == cntB[y] && check[cntA[x] - 1]) {
			ans.push_back(true);
		}
		else{
			ans.push_back(false);
		}
	}
	for(bool is_ok : ans) {
		if(is_ok){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}