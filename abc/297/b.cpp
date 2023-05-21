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

int main(){
	string s;
	cin >> s;
	int n = s.length();
	bool is_ok = true;
	// Bについて
	int b_idx = -1;
	REP(i, n){
		if(s[i] == 'B'){
			if(b_idx == -1){
				b_idx = i;
			}
			else{
				if(b_idx % 2 == i % 2){
					is_ok = false;
				}
			}
		}
	}
	// K,Rについて
	int cnt_r = 0;
	REP(i, n){
		if(s[i] == 'R'){
			++cnt_r;
		}
		if(s[i] == 'K'){
			if(cnt_r != 1){
				is_ok = false;
			}
		}
	}
	cout << (is_ok ? "Yes" : "No") << endl;
}