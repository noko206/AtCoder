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
const int MOD = 998244353;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
    ll x;
    cin >> x;
    map<ll, ll> dp;
    auto dfs = [&](auto& dfs, ll x) -> ll {
        if(x <= 4){
            return x;
        }
        if(dp.find(x) != dp.end()){
            return dp[x];
        }
        ll tmp1 = dfs(dfs, x / 2);
        ll tmp2 = dfs(dfs, (x + 1) / 2);
        ll tmp3 = (tmp1 * tmp2) % MOD;
        dp[x / 2] = tmp1;
        dp[(x + 1) / 2] = tmp2;
        dp[x] = tmp3;
        return dp[x];
    };
    cout << dfs(dfs, x) << endl;
    // for(pair<ll, ll> p : dp){
    //     cout << p.first << ' ' << p.second << endl;;
    // }
}