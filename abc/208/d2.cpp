#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

ll dp[405][405][405];

int main(){
    int n, m;
    cin >> n >> m;
    REP(k, n){
        REP(i, n){
            REP(j, n){
                dp[k][i][j] = LLINF;
            }
        }
    }
    REP(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        REP(k, max(a, b), n){
            dp[k][a][b] = c;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[k+1][i][j]=min(dp[k][i][j],dp[k][i][k]+dp[k][k][j]);
            }
        }
    }
    ll ans = 0;
    REP(k, n){
        REP(i, n){
            REP(j, n){
                if(dp[k][i][j] != LLINF){
                    ans += dp[k][i][j];
                }
            }
        }
    }
    cout << ans << endl;
}