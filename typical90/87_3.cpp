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

ll n, p, k;
ll a[40][40];
ll dp[40][40];

int get_cnt(ll x){
    REP(i, n){
        REP(j, n){
            if(a[i][j] == -1) dp[i][j] = x;
            else dp[i][j] = a[i][j];
        }
    }
    REP(m, n){
        REP(i, n){
            REP(j, n){
                chmin(dp[i][j], dp[i][m] + dp[m][j]);
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
    return cnt;
}

ll binary_search(ll x){
    ll ok = LLINF;
    ll ng = 1;
    REP(i, 40){
        ll mid = (ok + ng) / 2;
        int cnt = get_cnt(mid);
        if(cnt <= x){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return ok;
}

int main(){
    cin >> n >> p >> k;
    REP(i, n){
        REP(j, n){
            cin >> a[i][j];
        }
    }
    ll r = binary_search(k - 1);
    ll l = binary_search(k);
    if(r - l >= LLINF / 2){
        cout << "Infinity" << endl;
    }
    else{
        cout << r - l << endl;
    }
}