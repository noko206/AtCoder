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
	map<int, int> cnt;
	REP(i, n) ++cnt[a[i]];
	int tot = 0;
	vector<int> b;
	for(pair<int, int> p : cnt){
		tot += p.second - 1;
		b.push_back(p.first);
	}
	int idx = 1;
	int m = b.size();
	REP(i, m){
		if(b[i] == idx){
			++idx;
		}
		else{
			if(tot < 2) break;
			tot -= 2;
			b.push_back(idx);
			++idx;
			--i;
		}
	}
	idx = b.size() + 1;
	while(tot >= 2){
		b.push_back(idx);
		tot -= 2;
		++idx;
	}
	sort(ALL(b));
	if(tot == 1){
		if(b.size() == 1){
			b[0] = 1;
		}
		else{
			idx = 1;
			m = b.size();
			REP(i, m){
				if(b[i] == idx){
					++idx;
				}
				else{
					b[m - 1] = idx;
				}
			}
			sort(ALL(b));
		}
	}
	deque<int> dq;
	REP(i, b.size()) dq.push_back(b[i]);
	int ans = 0;
	while(true){
		if(dq.empty()) break;
		int v = dq.front();
		if(ans + 1 == v){
			dq.pop_front();
			++ans;
			continue;
		}
		if(dq.size() >= 2){
			dq.pop_back();
			dq.pop_back();
			++ans;
			continue;
		}
		break;
	}
	cout << ans << endl;
}