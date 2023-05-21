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

int p[1005][1005];

int main(){
    int n;
    cin >> n;
    REP(i, n){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        ++p[ly][lx];
        --p[ly][rx];
        --p[ry][lx];
        ++p[ry][rx];
    }
    REP(i, 1001){
        REP(j, 1000){
            p[i][j + 1] += p[i][j];
        }
    }
    REP(i, 1000){
        REP(j, 1001){
            p[i + 1][j] += p[i][j];
        }
    }
    vector<int> ans(n + 1, 0);
    REP(i, 1001){
        REP(j, 1001){
            ++ans[p[i][j]];
        }
    }
    REP(i, 1, n + 1){
        cout << ans[i] << endl;
    }
}