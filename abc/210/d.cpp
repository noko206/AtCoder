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

int main(){
    int h, w;
    ll c;
    cin >> h >> w >> c;
    vector<vector<int>> a(h);
    REP(i, h){
        a[i].resize(w);
        REP(j, w){
            cin >> a[i][j];
        }
    }
    ll ans = LLINF;
    REP(_, 2){
        vector<vector<ll>> dp(h, vector<ll>(w, LLINF));
        REP(i, h){
            REP(j, w){
                if(i - 1 >= 0){
                    chmin(dp[i][j], dp[i - 1][j]);
                }
                if(j - 1 >= 0){
                    chmin(dp[i][j], dp[i][j - 1]);
                }
                chmin(ans, dp[i][j] + a[i][j] + c * (i + j));
                chmin(dp[i][j], a[i][j] - c * (i + j));
            }
        }
        reverse(ALL(a));
    }
    cout << ans << endl;
}