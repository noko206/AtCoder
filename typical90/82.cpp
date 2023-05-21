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

using mint = modint1000000007;

mint sum(ll x){
	ll tmp = x;
	int cnt = 0;
	while(tmp > 0){
		tmp /= 10;
		++cnt;
	}
	mint ans = (mint)x * (x + 1) * cnt / 2;
	tmp = 1;
	REP(i, cnt - 1){
		tmp *= 10;
		tmp -= 1;
		ans -= (mint)tmp * (tmp + 1) / 2;
		tmp += 1;
	}
	return ans;
}

int main(){
	ll l, r;
	cin >> l >> r;
	--l;
	cout << (sum(r) - sum(l)).val() << endl;
}