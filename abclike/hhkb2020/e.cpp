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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	int masu = 0;
	REP(i, h){
		cin >> s[i];
		s[i] += '#';
		REP(j, w) if(s[i][j] == '.') ++masu;
	}
	string str = "";
	REP(i, w + 1){
		str += '#';
	}
	s.push_back(str);
	vector<vector<int>> cnt(h, vector<int>(w, -1));
	REP(i, h){
		int tot = 0;
		REP(j, w + 1){
			++tot;
			if(s[i][j] == '#' ){
				--tot;
				REP(k, tot){
					cnt[i][j - k - 1] += tot;
				}
				tot = 0;
			}
		}
	}
	REP(j, w){
		int tot = 0;
		REP(i, h + 1){
			++tot;
			if(s[i][j] == '#' ){
				--tot;
				REP(k, tot){
					cnt[i - k - 1][j] += tot;
				}
				tot = 0;
			}
		}
	}
	ll ans = 0;
	vector<ll> mod_pow(4000005);
	mod_pow[0] = 1;
	REP(i, 1, 4000005){
		mod_pow[i] = mod_pow[i - 1] * 2;
		mod_pow[i] %= MOD;
	}
	REP(i, h){
		REP(j, w){
			if(cnt[i][j] < 0) continue;
			ll tmp = mod_pow[cnt[i][j]] - 1;
			tmp %= MOD;
			tmp *= mod_pow[masu - cnt[i][j]];
			tmp %= MOD;
			ans += tmp;
			ans %= MOD;
		}
	}
	cout << ans << endl;
}