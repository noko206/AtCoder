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

vector<long long> divisor(long long n) {
	vector<long long> ret;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end()); // 昇順に並べる
	return ret;
}

int main(){
	ll k;
	cin >> k;
	vector<ll> d = divisor(k);
	int n = d.size();
	int ans = 0;
	REP(i, n){
		REP(j, i, n){
			ll a = d[i];
			ll b = d[j];
			ll c = (k / a) / b;
			if(c == 0) continue;
			if(a * b * c == k && b <= c){
				++ans;
			}
		}
	}
	cout << ans << endl;
}