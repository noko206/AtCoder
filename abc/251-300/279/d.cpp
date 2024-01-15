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

// __int128を使う場合, ifで定数と比較する場合はキャストする必要あり
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
	std::ostream::sentry s(dest);
	if (s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if (value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}

int main(){
	ll _a, _b;
	cin >> _a >> _b;
	__int128_t a, b;
	a = _a;
	b = _b;
	auto f = [&](ll x) -> double {
		return (double)b * x + ((double)a / sqrtl(1 + x));
	};
	ll low = 0;
	ll high = INF64;
	int cnt = 100000;
	while (cnt--) {
		ll c1 = (low * 2 + high) / 3;
		ll c2 = (low + high * 2) / 3;
		if (f(c1) > f(c2)) low = c1;
		else high = c2;
	}
	cout << fixed << setprecision(20) << min({f(low), f(high), f((low + high) / 2)}) << endl;
}