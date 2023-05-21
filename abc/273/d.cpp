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
	int h, w, rs, cs, n;
	cin >> h >> w >> rs >> cs >> n;
	unordered_map<int, set<int>> y_to_x, x_to_y;
	REP(i, n){
		int r, c;
		cin >> r >> c;
		y_to_x[r].insert(c); // y->x
		x_to_y[c].insert(r); // x->y
	}
	int q;
	cin >> q;
	vector<pair<int, int>> ans(q);
	int y, x;
	y = rs;
	x = cs;
	REP(i, q){
		char d;
		int l;
		cin >> d >> l;
		int max, res;
		if(d == 'U'){
			max = 0;
			if(x_to_y.find(x) != x_to_y.end()){
				auto it = x_to_y[x].lower_bound(y);
				if(it != x_to_y[x].begin()){
					--it;
					max = *it;
				}
			}
			res = y - l;
			if(res <= max){
				res = max + 1;
			}
			y = res;
		}
		if(d == 'D'){
			max = h + 1;
			if(x_to_y.find(x) != x_to_y.end()){
				auto it = x_to_y[x].upper_bound(y);
				if(it != x_to_y[x].end()) {
					max = *it;
				}
			}
			res = y + l;
			if(res >= max){
				res = max - 1;
			}
			y = res;
		}
		if(d == 'L'){
			max = 0;
			if(y_to_x.find(y) != y_to_x.end()){
				auto it = (y_to_x[y]).lower_bound(x);
				if(it != y_to_x[y].begin()){
					--it;
					max = *it;
				}
			}
			res = x - l;
			if(res <= max){
				res = max + 1;
			}
			x = res;
		}
		if(d == 'R'){
			max = w + 1;
			if(y_to_x.find(y) != y_to_x.end()){
				auto it = y_to_x[y].upper_bound(x);
				if(it != y_to_x[y].end()) {
					max = *it;
				}
			}
			res = x + l;
			if(res >= max){
				res = max - 1;
			}
			x = res;
		}
		ans[i] = {y, x};
	}
	REP(i, q){
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
}