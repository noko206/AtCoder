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

struct BIT {
	int n;          // 配列の要素数(数列の要素数+1)
	vector<int> bit;  // データの格納先
	BIT(int n_) : n(n_ + 1), bit(n, 0) {}
	void add(int i, int x) {
		for (int idx = i; idx < n; idx += (idx & -idx)) {
			bit[idx] += x;
		}
	}
	int sum(int i) {
		int s(0);
		for (int idx = i; idx > 0; idx -= (idx & -idx)) {
			s += bit[idx];
		}
		return s;
	}
};

int main(){
	int height, width, n, h, w;
	cin >> height >> width >> n >> h >> w;
	vector<vector<int>> a(height, vector<int>(width));
	vector<int> cnt(n + 1, 0);
	REP(i, height) REP(j, width) {
		cin >> a[i][j];
		++cnt[a[i][j]];
	}
	BIT bit(n);
	REP(i, 1, n + 1) {
		if(cnt[i] > 0) bit.add(i, 1);
	}
	vector<vector<int>> ans(height - h + 1, vector<int>(width - w + 1));
	ans[0][0] = bit.sum(n);
	REP(k, height - h + 1){
		REP(l, width - w + 1){
			if(l == 0){
				REP(i, h){
					REP(j, w){
						--cnt[a[k + i][j]];
						if(cnt[a[k + i][j]] == 0) bit.add(a[k + i][j], -1);
					}
				}
			}
			else{
				REP(i, h){
					++cnt[a[k + i][l - 1]];
					if(cnt[a[k + i][l - 1]] == 1) bit.add(a[k + i][l - 1], 1);
				}
				REP(i, h){
					--cnt[a[k + i][l + w - 1]];
					if(cnt[a[k + i][l + w - 1]] == 0) bit.add(a[k + i][l + w - 1], -1);
				}
			}
			ans[k][l] = bit.sum(n);
		}
		REP(i, h){
			REP(j, w){
				++cnt[a[k + i][(width - w) + j]];
				if(cnt[a[k + i][(width - w) + j]] == 1) bit.add(a[k + i][(width - w) + j], 1);
			}
		}
	}
	REP(i, height - h + 1){
		REP(j, width - w + 1){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
}