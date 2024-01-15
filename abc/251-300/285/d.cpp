#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
	vector<string> s(n), t(n);
	REP(i, n) cin >> s[i] >> t[i];
	unordered_set<string> st;
	REP(i, n){
		st.insert(s[i]);
		st.insert(t[i]);
	}
	int idx = 0;
	unordered_map<string, int> mp;
	for(auto v: st){
		mp[v] = idx;
		++idx;
	}
	scc_graph g(mp.size());
	REP(i, n){
		g.add_edge(mp[s[i]], mp[t[i]]);
	}
	for(auto v: g.scc()){
		if(v.size() >= 2){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}