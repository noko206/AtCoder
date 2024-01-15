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
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
    string s;
    cin >> s;
    string t = "";
    REP(i, 100){
        t += "oxx";
    }
    int n = s.length();
    int m = t.length();
    bool is_ok = true;
    REP(i, m - n + 1){
        is_ok = true;
        REP(j, n){
            if(s[j] != t[i + j]){
                is_ok = false;
            }
        }
        if(is_ok){
            break;
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}