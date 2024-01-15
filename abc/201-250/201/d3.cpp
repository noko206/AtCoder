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

int dp[2005][2005];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h){
        cin >> a[i];
    }
    int p[h][w];
    REP(i, h){
        REP(j, w){
            p[i][j] = a[i][j] == '+' ? 1 : -1;
        }
    }
    dp[h - 1][w - 1] = 0;
    for (int i = h - 1; i >= 0; --i){
        for (int j = w - 1; j >= 0; --j){
            if(i == h - 1 && j == w - 1){
                continue;
            }
            if((i + j) % 2 == 0){
                dp[i][j] = -INF;
                if (j + 1 < w){
                    chmax(dp[i][j], dp[i][j + 1] + p[i][j + 1]);
                }
                if(i + 1 < h){
                    chmax(dp[i][j], dp[i + 1][j] + p[i + 1][j]);
                }
            }
            else{
                dp[i][j] = INF;
                if (j + 1 < w){
                    chmin(dp[i][j], dp[i][j + 1] - p[i][j + 1]);
                }
                if(i + 1 < h){
                    chmin(dp[i][j], dp[i + 1][j] - p[i + 1][j]);
                }
            }
        }
    }
    if(dp[0][0] == 0){
        cout << "Draw" << endl;
    }
    if(dp[0][0] > 0){
        cout << "Takahashi" << endl;
    }
    if(dp[0][0] < 0){
        cout << "Aoki" << endl;
    }
    // REP(i, h){
    //     REP(j, w){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}