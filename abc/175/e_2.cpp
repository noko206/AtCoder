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

ll dp[3005][3005][5];

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> v(h, vector<int>(w, 0));
    REP(i, k){
        int r, c;
        cin >> r >> c;
        --r, --c;
        cin >> v[r][c];
    }
    dp[0][0][1] = v[0][0];
    REP(i, h){
        REP(j, w){
            REP(k, 4){
                if(i + 1 < h){
                    chmax(dp[i + 1][j][0], dp[i][j][k]);
                    chmax(dp[i + 1][j][1], dp[i][j][k] + v[i + 1][j]);
                }
                if(j + 1 < w){
                    chmax(dp[i][j + 1][k], dp[i][j][k]);
                    if(k + 1 < 4){
                        chmax(dp[i][j + 1][k + 1], dp[i][j][k] + v[i][j + 1]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    REP(k, 4){
        chmax(ans, dp[h - 1][w - 1][k]);
    }
    cout << ans << endl;
}