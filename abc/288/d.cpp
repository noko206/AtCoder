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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<ll> c(n, 0);
	vector<ll> d(n, 0);
	REP(i, n){
		d[i] -= a[i] + c[i];
		REP(j, k){
			if(i + j < n) {
				c[i + j] += d[i];
			}
		}
	}
	int q;
	cin >> q;
	vector<bool> ans(q);
	REP(i, n) cout << d[i] << ' ';
	cout << endl;
	REP(i, q){
		int l, r;
		cin >> l >> r;
		ll tot = 0;
		bool is_ok = true;
		REP(j, r - k + 1, r){
			tot += a[j - 1] - a[j];
			if(j > r - k){
				if(c[j] - tot + a[j] != 0){
					is_ok = false;
				}
			}
		}
		ans[i] = is_ok;
	}
	REP(i, q){
		if(ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}