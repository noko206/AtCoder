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
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	REP(i, n){
		a[i].resize(5);
		REP(j, 5){
			cin >> a[i][j];
		}
	}
	int ok = 1;
	int ng = INF32;
	while(ng - ok != 1){
		int mid = (ok + ng) / 2;
		multiset<int> s;
		REP(i, n){
			int tmp = 0;
			REP(j, 5){
				tmp <<= 1;
				if(a[i][j] >= mid){
					++tmp;
				}
			}
			if(s.count(tmp) < 3){
				s.insert(tmp);
			}
		}
		vector<int> sa;
		for(int v : s){
			sa.push_back(v);
		}
		int m = sa.size();
		bool is_ok = false;
		REP(i, m){
			REP(j, i){
				REP(k, j){
					int chk = 0;
					REP(l, 5){
						chk |= (sa[i] & (1 << l)) | (sa[j] & (1 << l)) | (sa[k] & (1 << l));
					}
					if(chk == 31){
						is_ok = true;
					}
				}
			}
		}
		if(is_ok){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	cout << ok << endl;
}