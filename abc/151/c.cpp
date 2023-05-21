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
	int n, m;
	cin >> n >> m;
	vector<bool> is_AC(n, false);
	vector<int> cnt_WA(n, 0);
	REP(i, m){
		int p;
		string s;
		cin >> p >> s;
		--p;
		if(!is_AC[p]){
			if(s == "AC"){
				is_AC[p] = true;
			}
			else{
				++cnt_WA[p];
			}
		}
	}
	int ans_AC = 0;
	int ans_WA = 0;
	REP(i, n){
		if(is_AC[i]){
			++ans_AC;
			ans_WA += cnt_WA[i];
		}
	}
	cout << ans_AC << ' ' << ans_WA << endl;
}