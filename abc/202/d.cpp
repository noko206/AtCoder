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

ll dp[65][65];
string ans = "";

void dfs(int a, int b, ll k, string str){
    if(a < 0 || b < 0 || ans != ""){
        return;
    }
    if(a == 0 && b == 0){
        if(k == 1){
            ans = str;
        }
        return;
    }
    if(a > 0){
        if(dp[a - 1 + b][b] >= k){
            dfs(a - 1, b, k, str + "a");
        }
    }
    if(b > 0){
        if(a > 0){
            if(dp[a - 1 + b][b] >= k){
                return;
            }
            k -= dp[a - 1 + b][b];
        }
        dfs(a, b - 1, k, str + "b");
    }
}

int main(){
    int a, b;
    ll k;
    cin >> a >> b >> k;
    dp[0][0] = 1;
    REP(i, 61){
        REP(j, 61){
            if(i - 1 >= 0){
                dp[i][j] += dp[i - 1][j];
                if(j - 1 >= 0){
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
    }
    dfs(a, b, k, "");
    cout << ans << endl;
}