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
	ll l, n1, n2;
	cin >> l >> n1 >> n2;
	vector<pair<ll, ll>> top(n1), bottom(n2);
	REP(i, n1){
		ll v, l;
		cin >> v >> l;
		top[i] = {v, l};
	}
	REP(i, n2){
		ll v, l;
		cin >> v >> l;
		bottom[i] = {v, l};
	}
	int i = 0, j = 0;
	ll top_over = max(top[i].second - bottom[i].second, 0LL);
	ll bottom_over = max(bottom[i].second - top[i].second, 0LL);
	ll ans = 0;
	while(true){
		// cout << top_over << ' ' << bottom_over << endl;
		if(top[i].first == bottom[j].first){
			if(top_over == bottom_over){
				ans += min(top[i].second, bottom[j].second);
			}
			else if(top_over > bottom_over) {
				ans += min(top[i].second - top_over, bottom[j].second);
			}
			else{
				ans += min(bottom[j].second - bottom_over, top[i].second);
			}
		}
		if(top_over == bottom_over){
			++i; ++j;
			if(i >= n1 || j >= n2) break;
			top_over = max(top[i].second - bottom[j].second, 0LL);
			bottom_over = max(bottom[j].second - top[i].second, 0LL);
		}
		else if(top_over > bottom_over){
			++j;
			if(j >= n2) break;
			bottom_over = max(bottom[j].second - top_over, 0LL);
			top_over = max(top_over - bottom[j].second, 0LL);
		}
		else{
			++i;
			if(i >= n1) break;
			top_over = max(top[i].second - bottom_over, 0LL);
			bottom_over = max(bottom_over - top[i].second, 0LL);
		}
	}
	cout << ans << endl;
}