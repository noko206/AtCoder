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

bool dp[200005][5];

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    REP(i, n){
        cin >> a[i];
    }
    REP(i, n){
        cin >> b[i];
    }
    dp[0][0] = true;
    dp[0][1] = true;
    REP(i, 1, n){
        if(dp[i - 1][0]){
            if(abs(a[i - 1] - a[i]) <= k){
                dp[i][0] = true;
            }
            if(abs(a[i - 1] - b[i]) <= k){
                dp[i][1] = true;
            }
        }
        if(dp[i - 1][1]){
            if(abs(b[i - 1] - a[i]) <= k){
                dp[i][0] = true;
            }
            if(abs(b[i - 1] - b[i]) <= k){
                dp[i][1] = true;
            }
        }
    }
    if(dp[n - 1][0] || dp[n - 1][1]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}