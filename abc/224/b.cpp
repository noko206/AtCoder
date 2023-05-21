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
    int h, w;
    cin >> h >> w;
    bool is_ok = true;
    vector<vector<ll>> a(h);
    REP(i, h){
        a[i].resize(w);
        REP(j, w){
            cin >> a[i][j];
        }
    }
    REP(i2, h){
        REP(j2, w){
            REP(i1, i2){
                REP(j1, j2){
                    if(a[i1][j1] + a[i2][j2] <= a[i2][j1] + a[i1][j2]){
                        continue;
                    }
                    is_ok = false;
                }
            }
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}