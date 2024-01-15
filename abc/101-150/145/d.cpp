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

map<pair<int, int>, ll> dp;

int rec(int x, int y){
    if(x < 0 || y < 0) return 0;
    pair<int, int> pos = make_pair(x, y);
    if(dp.find(pos) != dp.end()) return dp[pos];
    if(x == 0 && y == 0) return 1;
    ll ans = 0;
    if((x - 1) * 2 >= y - 2 && (y - 2) * 2 >= x - 1){
        ans += dp[make_pair(x - 1, y - 2)] = rec(x - 1, y - 2);
    }
    if((x - 2) * 2 >= y - 1 && (y - 1) * 2 >= x - 2){
        ans += dp[make_pair(x - 2, y - 1)] = rec(x - 2, y - 1);
    }
    return ans % MOD;
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << rec(x, y) << endl;
}