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

ll dp[1 << 17][17];
vector<int> x(17), y(17), z(17);

int get_cost(int v, int u){
    return abs(x[u] - x[v]) + abs(y[u] - y[v]) + max(0, z[u] - z[v]);
}

int main(){
    int n;
    cin >> n;
    REP(i, n){
        cin >> x[i] >> y[i] >> z[i];
    }
    REP(i, 1 << n){
        REP(j, n){
            dp[i][j] = LLINF;
        }
    }
    dp[1][0] = 0;
    REP(i, 1 << n){
        REP(j, n){
            if(!(i & (1 << j))){
                continue;
            }
            REP(k, n){
                if(i & (1 << k)){
                    continue;
                }
                if(dp[i][j] == LLINF){
                    continue;
                }
                chmin(dp[i | (1 << k)][k], dp[i][j] + get_cost(j, k));
            }
        }
    }
    ll ans = LLINF;
    REP(i, 1, n){
        chmin(ans, dp[(1 << n) - 1][i] + get_cost(i, 0));
    }
    cout << ans << endl;
}