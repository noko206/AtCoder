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

int dp[26][100100];

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    REP(i, 26){
        dp[i][n] = INF;
    }
    REP(i, 26){
        REP(j, n){
            if(s[n - (j + 1)] == i + 'a'){
                dp[i][n - (j + 1)] = n - (j + 1);
            }
            else{
                dp[i][n - (j + 1)] = dp[i][n - j];
            }
        }
    }
    int p = 0;
    string ans = "";
    REP(i, 26){
        if(ans.length() == k){
            break;
        }
        if(dp[i][p] <= n - (k - ans.length())){
            ans += i + 'a';
            p = dp[i][p] + 1;
            i = -1;
        }
    }
    // REP(i, 26){
    //     printf("%c:", i + 'a');
    //     REP(j, n){
    //         if(dp[i][j] == INF){
    //             cout << -1 << ' ';
    //             continue;
    //         }
    //         printf("%2d ", dp[i][j]);
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
}