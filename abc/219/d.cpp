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

int dp[305][305][305];

int main(){
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(n);
    REP(i, n){
        cin >> a[i] >> b[i];
    }
    REP(i, x + 1){
        REP(j, y + 1){
            dp[0][i][j] = INF;
        }
    }
    REP(i, n){
        REP(j, x + 1){
            REP(k, y + 1){
                if(j <= a[i] && k <= b[i]){
                    dp[i + 1][j][k] = 1;
                }
                else{
                    dp[i + 1][j][k] = min(dp[i][j][k], dp[i][max(j - a[i], 0)][max(k - b[i], 0)] + 1);
                }
            }
        }
    }
    if(dp[n][x][y] == INF){
        cout << -1 << endl;
    }
    else{
        cout << dp[n][x][y] << endl;
    }
}