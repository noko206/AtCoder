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

int dp[1005][10005];

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    REP(i, n){
        cin >> a[i] >> b[i];
    }
    REP(i, n + 1){
        REP(j, h + 1){
            dp[i][j] = INF;
        }
    }
    dp[0][h] = 0;
    REP(i, n){
        if(i > 0){
            for(int j = h; j >= 0; --j){
                chmin(dp[i][max(j - a[i], 0)], dp[i][j] + b[i]);
                chmin(dp[i][j], dp[i][j]);
            }
        }
        REP(j, h + 1){
            chmin(dp[i + 1][max(j - a[i], 0)], dp[i][j] + b[i]);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[n][0] << endl;
}