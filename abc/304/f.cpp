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

using mint = modint998244353;

vector<ll> enum_divisors(ll x){
	vector<ll> ans;
	for(ll i = 1; i * i <= x; ++i){
		if(x % i == 0){
			ans.push_back(i);
			if(x / i != i){
				ans.push_back(x / i);
			}
		}
	}
	sort(ALL(ans));
	return ans;
}

int naive(int n, string s){
	auto d = enum_divisors(n);
	int ans = 0;
	REP(bit, 1 << n){
		vector<bool> is_work(n, false);
		REP(i, n){
			if(bit & (1 << n)) is_work[i] = true;
		}
		bool is_ok = true;
		REP(i, n){
			if(s[i] == '.' && !is_work[i]) is_ok = false;
		}
		if(!is_ok) continue;
		REP(i, d.size()){
			bool same = true;
			REP(k, d.size()){
				for(int j = k + d[i]; j < n; j += d[i]){
					if(is_work[j] != is_work[j - d[i]]){
						same = false;
					}
				}
			}
			if(same){
				++ans;
				break;
			}
		}
	}
	return ans;
}

int solve(int n, string s){
	vector<bool> is_prime(200001, true);
	is_prime[0] = false;
	is_prime[1] = false;
	REP(i, 2, 200001){
		if(!is_prime[i]) continue;
		for(int j = i * 2; j <= 200000; j += i){
			is_prime[j] = false;
		}
	}

	auto d = enum_divisors(n);
	reverse(ALL(d));
	mint ans = 0;

	REP(i, 1, d.size()){
		bool is_continue = false;
		REP(j, 1, i){
			if(d[j] % d[i] == 0) is_continue = true;
		}
		if(is_continue) continue;
		mint tmp = 1;
		REP(j, d[i]){
			bool is_all_one = true;
			for(int k = j; k < n; k += d[i]){
				if(s[k] == '.') is_all_one = false;
			}
			tmp *= is_all_one ? 2 : 1;
		}
		tmp -= 1;
		ans += tmp;
	}
	ans += 1;
	return ans.val();
}

int main(){
	int n;
	string s;
	cin >> n >> s;

	output(naive(n, s));
	output(solve(n, s));
}