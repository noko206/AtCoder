#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(int i=int(a);i>=int(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

int main(){
	ll n;
	cin >> n;
	vector<bool> sieve(1000001, true);
	sieve[0] = sieve[1] = false;
	vector<int> primes;
	REP(i, 2, 1000001){
		if(!sieve[i]) continue;
		for(int j = i * 2; j < 1000001; j += i){
			sieve[j] = false;
		}
	}
	REP(i, 1000001){
		if(sieve[i]){
			primes.push_back(i);
		}
	}
	unordered_set<ll> st;
	int m = primes.size();
	REP(i, m){
		ll a = primes[i];
		if(a * a * a * a * a > n) break;
		REP(j, i + 1, m){
			ll b = primes[j];
			if(a * a * b * b * b > n) break;
			REP(k, j + 1, m){
				ll c = primes[k];
				if(a * a * b * c * c > n) break;
				st.insert(a * a * b * c * c);
			}
		}
	}
	output(st.size());
}