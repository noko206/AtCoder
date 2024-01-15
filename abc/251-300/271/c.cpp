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

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	sort(ALL(a));
	deque<int> dq;
	REP(i, n) dq.push_back(a[i]);
	vector<bool> is_having(n + 5, false);
	unordered_map<int, bool> mp;
	int idx = 1;
	int cnt = 0;
	vector<int> b;
	REP(i, n){
		int v = dq.front();
		dq.pop_front();
		// 重複していない
		if(mp.find(v) == mp.end()){
			if(v <= n){
				is_having[v] = true;
			}
			mp[v] = true;
			b.push_back(v);
		}
		// 重複している
		else{
			++cnt;
			if(cnt == 2){
				while(is_having[idx]){
					++idx;
				}
				is_having[idx] = true;
				mp[idx] = true;
				cnt -= 2;
				b.push_back(idx);
			}
		}
	}
	sort(ALL(b));
	dq.clear();
	REP(i, b.size()) dq.push_back(b[i]);
	int ans = 0;
	cnt = 0;
	while(true){
		if(dq.empty()) break;
		int v = dq.front();
		if(ans + 1 == v){
			dq.pop_front();
			++cnt;
			++ans;
			continue;
		}
		if(cnt >= 2){
			++ans;
			--cnt;
			continue;
		}
		if(dq.empty()){
			if(cnt == 1){
				++ans;
			}
			break;
		}
		int u = dq.back();
		dq.pop_back();
		++ans;
	}
	cout << ans << endl;
}