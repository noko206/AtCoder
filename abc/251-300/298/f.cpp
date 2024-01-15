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
	int n;
	cin >> n;
	vector<ll> r(n), c(n), x(n);
	REP(i, n) cin >> r[i] >> c[i] >> x[i];
	map<int, vector<int>> c_to_r;
	map<int, ll> yoko, tate;
	map<pair<int, int>, int> rc_to_x;
	REP(i, n){
		yoko[r[i]] += x[i];
		tate[c[i]] += x[i];
		c_to_r[c[i]].push_back(r[i]);
		rc_to_x[{r[i], c[i]}] = x[i];
	}
	multiset<pair<ll, int>> yoko_sum;
	for(auto p : yoko){
		yoko_sum.insert({p.second, p.first});
	}
	ll ans = 0;
	for (auto p : tate){
		int _c = p.first;
		ll c_sum = p.second;
		vector<pair<ll, int>> erase_list, insert_list;
		for (auto _r : c_to_r[_c]) {
			auto it = yoko_sum.find({yoko[_r], _r});
			ll _sum = (*it).first;
			insert_list.push_back({_sum, _r}); // あとで戻す
			yoko_sum.erase(it);
			ll new_sum = _sum - rc_to_x[{_r, _c}];
			yoko_sum.insert({new_sum, _r});
			erase_list.push_back({new_sum, _r}); // あとで消す
		}
		auto it = yoko_sum.end();
		--it;
		chmax(ans, c_sum + (*it).first);
		for (auto _p : erase_list){
			yoko_sum.erase(yoko_sum.find(_p));
		}
		for (auto _p : insert_list){
			yoko_sum.insert(_p);
		}
	}
	cout << ans << endl;
}