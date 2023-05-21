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

int dp[105][100100];

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    REP(i, n){
        cin >> a[i] >> b[i];
    }
    REP(i, n + 1){
        REP(j, s + 1){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    REP(i, n){
        REP(j, s + 1){
            if(dp[i][j] == -1){
                continue;
            }
            if(j + a[i] <= s){
                dp[i + 1][j + a[i]] = j;
            }
            if(j + b[i] <= s){
                dp[i + 1][j + b[i]] = j;
            }
        }
    }
    if(dp[n][s] == -1){
        cout << "Impossible" << endl;
    }
    else{
        int j = s;
        string ans = "";
        for (int i = n; i > 0; --i){
            // cout << j - dp[i][j] << endl;
            if(j - dp[i][j] == a[i - 1]){
                ans += "A";
            }
            else{
                ans += "B";
            }
            j = dp[i][j];
        }
        reverse(ALL(ans));
        cout << ans << endl;
    }
}