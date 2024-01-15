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

template <typename T>
struct BIT {
	int n;
	vector<T> bit;
	BIT(int n_) : n(n_ + 1), bit(n, 0) {}
	void add(int i, T x) {
		for (int idx = i; idx < n; idx += (idx & -idx)) {
			bit[idx] += x;
		}
	}
	T sum(int i) {
		T s(0);
		for (int idx = i; idx > 0; idx -= (idx & -idx)) {
			s += bit[idx];
		}
		return s;
	}
	int lower_bound(T w) { // a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
		if (w <= 0) {
			return 0;
		} else {
			int x = 0, r = 1;
			while (r < n) r = r << 1;
			for (int len = r; len > 0; len = len >> 1) { // 長さlenは1段下るごとに半分に
				if (x + len < n && bit[x + len] < w) { // 採用するとき
					w -= bit[x + len];
					x += len;
				}
			}
			return x + 1;
		}
	}
};

int main(){
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> x(q), y(q);
	REP(i, q) cin >> x[i] >> y[i], --x[i];
	// 座圧
	unordered_map<int, int> compress;
	vector<int> z(q + 1, 0);
	REP(i, q) z[i] = y[i];
	sort(ALL(z));
	int id = 1;
	REP(i, q + 1) if(compress.find(z[i]) == compress.end()) {
		compress[z[i]] = id++;
	}
	BIT<ll> bit(q + 1);
	BIT<int> cnt(q + 1);
	vector<ll> ans(q);
	vector<int> a(n, 0);
	REP(i, q){
		int comp_a = compress[a[x[i]]];
		if(cnt.sum(comp_a) - cnt.sum(comp_a - 1) > 0){
			cnt.add(comp_a, -1);
			bit.add(comp_a, -a[x[i]]);
		}
		a[x[i]] = y[i];
		comp_a = compress[a[x[i]]];
		cnt.add(comp_a, 1);
		bit.add(comp_a, a[x[i]]);
		int cnt_sum = cnt.sum(q + 1);
		if(cnt_sum <= k){
			ans[i] = bit.sum(q + 1);
		} else {
			int it = cnt.lower_bound(cnt_sum - k);
			int tmp = cnt.sum(q + 1) - cnt.sum(it);
			ans[i] = bit.sum(q + 1) - bit.sum(it) + ((bit.sum(it) - bit.sum(it - 1)) / (cnt.sum(it) - cnt.sum(it - 1))) * (k - tmp);
		}
	}
	REP(i, q){
		output(ans[i]);
	}
}