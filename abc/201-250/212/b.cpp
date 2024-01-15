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
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    string x;
    cin >> x;
    vector<int> a(4);
    REP(i, 4){
        a[i] = x[i] - '0';
    }
    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]){
        cout << "Weak" << endl;
    }
    else if((a[0] + 1) % 10 == a[1] && (a[1] + 1) % 10 == a[2] && (a[2] + 1) % 10 == a[3]){
        cout << "Weak" << endl;
    }
    else{
        cout << "Strong" << endl;
    }
}