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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	multiset<int> sm, sk;
	unordered_map<int, int> cntm, cntk;
	ll sum = 0;
	vector<int> b(m);
	REP(i, m){
		b[i] = a[i];
	}
	sort(ALL(b));
	REP(i, m){
		sm.insert(b[i]);
		cntm[b[i]]++;
		if(i < k) {
			sk.insert(b[i]);
			sum += b[i];
			cntk[b[i]]++;
		}
	}
	cout << sum << ' ';
	REP(i, n - m){
		sm.erase(sm.find(a[i]));
		cntm[a[i]]--;
		if(sk.find(a[i]) != sk.end()) {
			sk.erase(sk.find(a[i]));
			cntk[a[i]]--;
			sum -= a[i];
		}

		sm.insert(a[i + m]);
		cntm[a[i + m]]++;

		if(sk.size() == 0){
			sk.insert(a[i + m]);
			cntk[a[i + m]]++;
			sum += a[i + m];
		}

		// a[i + m]を追加する？
		auto it = sk.end(); it--;
		if(a[i + m] < *it){
			if(sk.size() == k) {
				sk.erase(it);
				cntk[*it]--;
				sum -= *it;
			}
			sk.insert(a[i + m]);
			cntk[a[i + m]]++;
			sum += a[i + m];
		}

		if(sk.size() != k){
			auto it2 = sk.end(); it2--;
			auto it3 = sm.lower_bound(*it2);
			if(cntm[*it3] == cntk[*it3]){
				auto it4 = sm.upper_bound(*it2);
				sk.insert(*it4);
				cntk[*it4]++;
				sum += *it4;
			}
			else{
				sk.insert(*it3);
				cntk[*it3]++;
				sum += *it3;
			}
		}
		cout << sum << ' ';
	}
	cout << endl;
}