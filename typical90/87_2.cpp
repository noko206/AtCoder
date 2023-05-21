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

int main(){
    int n, p, k;
    cin >> n >> p >> k;
    vector<vector<ll>> a(n);
    REP(i, n){
        a[i].resize(n);
        REP(j, n){
            cin >> a[i][j];
        }
    }
    ll high = 5000000000LL;
    ll ok = 5000000000LL;
    ll ng = 1;
    while(abs(ng - ok) != 1){
        ll mid = (ok + ng) / 2LL;
        vector<vector<ll>> dp = a;
        REP(i, n){
            REP(j, n){
                if(dp[i][j] == -1){
                    dp[i][j] = mid;
                }
            }
        }
        REP(l, n){
            REP(i, n){
                REP(j, n){
                    chmin(dp[i][j], dp[i][l] + dp[l][j]);
                }
            }
        }
        int cnt = 0;
        REP(i, n){
            REP(j, i + 1, n){
                if(dp[i][j] <= (ll)p){
                    ++cnt;
                }
            }
        }
        if(cnt <= k - 1){
            ok = mid;
            chmin(high, ok);
        }
        else{
            ng = mid;
        }
    }
    ll low = 5000000000LL;
    ok = 5000000000LL;
    ng = 1;
    while(abs(ng - ok) != 1){
        ll mid = (ok + ng) / 2LL;
        vector<vector<ll>> dp = a;
        REP(i, n){
            REP(j, n){
                if(dp[i][j] == -1){
                    dp[i][j] = mid;
                }
            }
        }
        REP(l, n){
            REP(i, n){
                REP(j, n){
                    chmin(dp[i][j], dp[i][l] + dp[l][j]);
                }
            }
        }
        int cnt = 0;
        REP(i, n){
            REP(j, i + 1, n){
                if(dp[i][j] <= (ll)p){
                    ++cnt;
                }
            }
        }
        if(cnt <= k){
            ok = mid;
            chmin(low, ok);
        }
        else{
            ng = mid;
        }
    }
    if(high - low >= 2000000000LL){
        cout << "Infinity" << endl;
    }
    else{
        cout << high - low << endl;
    }
}