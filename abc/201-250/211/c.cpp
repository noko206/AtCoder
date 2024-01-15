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

ll dp[10][100005];

int main(){
    string s;
    cin >> s;
    int len = s.length();
    const string chokudai = "chokudai";
    REP(j, len){
        if(s[j] == chokudai[0]){
            ++dp[0][j];
        }
        if(j > 0){
            dp[0][j] += dp[0][j - 1];
        }
    }
    REP(i, 1, 8){
        REP(j, i, len){
            if(s[j] == chokudai[i]){
                if(dp[i - 1][j] != 0){
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
            else{
                dp[i][j] = dp[i][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }
    // REP(i, 8){
    //     REP(j, len){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[7][len - 1] << endl;
}