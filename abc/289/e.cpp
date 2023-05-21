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
	int t;
	cin >> t;
	vector<int> ans;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> c(n);
		REP(i, n) cin >> c[i];
		vector<vector<int>> to(n);
		REP(i, m){
			int u, v;
			cin >> u >> v;
			--u; --v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		vector<int> takahashi(n, -1);
		vector<int> aoki(n, -1);
		takahashi[0] = 0;
		aoki[n - 1] = 0;
		queue<int> takahashi_q, aoki_q;
		takahashi_q.push(0);
		aoki_q.push(n - 1);
		bool takahashi_red = false;
		bool takahashi_blue = false;
		bool aoki_red = false;
		bool aoki_blue = false;
		int cnt = 0;
		int num = -1;
		while(2 * m > cnt && !takahashi_q.empty() && !aoki_q.empty()){
			int k = takahashi_q.size();
			for(int i = 0; i < k; ++i) {
				int v = takahashi_q.front(); takahashi_q.pop();
				for (int u : to[v]){
					if(c[u] == 0) takahashi_red = true;
					else takahashi_blue = true;
				}
				takahashi_q.push(v);
			}
			k = aoki_q.size();
			for(int i = 0; i < k; ++i) {
				int v = aoki_q.front(); aoki_q.pop();
				for (int u : to[v]){
					if(c[u] == 0) aoki_red = true;
					else aoki_blue = true;
				}
				aoki_q.push(v);
			}
			bool takahashi_ok = false;
			bool aoki_ok = false;
			k = takahashi_q.size();
			for(int i = 0; i < k; ++i) {
				int v = takahashi_q.front(); takahashi_q.pop();
				for (int u : to[v]){
					if(c[u] == 0) {
						if(aoki_blue) {
							takahashi_q.push(u);
							if(u == n - 1) {
								takahashi_ok = true;
							}
						}
					}
					else {
						if(aoki_red) {
							takahashi_q.push(u);
							if(u == n - 1){
								takahashi_ok = true;
							}
						}
					}
				}
			}
			k = aoki_q.size();
			for(int i = 0; i < k; ++i) {
				int v = aoki_q.front(); aoki_q.pop();
				for (int u : to[v]){
					if(c[u] == 0) {
						if(takahashi_blue) {
							aoki_q.push(u);
							if(u == 0) {
								aoki_ok = true;
							}
						}
					}
					else {
						if(takahashi_red) {
							aoki_q.push(u);
							if(u == 0){
								aoki_ok = true;
							}
						}
					}
				}
			}
			++cnt;
			if(takahashi_ok && aoki_ok){
				num = cnt;
				break;
			}
		}
		ans.push_back(num);
	}
	for(int v: ans) cout << v << endl;
}