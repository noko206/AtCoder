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

ll dp[405][405];

int main(){
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    REP(i, m){
        cin >> a[i];
    }
    REP(i, m + 1){
        REP(j, m + 1){
            dp[i][j] = LLINF;
        }
        if(i + 1 <= m) dp[i][i + 1] = abs(a[i] - a[i + 1]);
    }
    for(int i = 3; i < m; i += 2){
        REP(j, m - i){
            int l = j;
            int r = j + i;
            REP(k, l, r + 1){
                chmin(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
            chmin(dp[l][r], dp[l + 1][r - 1] + abs(a[l] - a[r]));
        }
    }
    cout << dp[0][m - 1] << endl;
}