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
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    REP(i, n){
        cin >> x[i] >> y[i];
    }
    if(k == 1){
        cout << "Infinity" << endl;
        return 0;
    }
    vector<vector<int>> t(n, vector<int>(n, 2));
    REP(i, n){
        REP(j, i + 1, n){
            REP(k, j + 1, n){
                ll dx1 = x[k] - x[i], dy1 = y[k] - y[i];
                ll dx2 = x[j] - x[i], dy2 = y[j] - y[i];
                if(dx1 * dy2 == dx2 * dy1){
                    ++t[i][j];
                }
            }
        }
    }
    ll ans = 0;
    REP(i, n){
        REP(j, i + 1, n){
            if(t[i][j] >= k){
                ++ans;
            }
            if(t[i][j] > k){
                ans -= t[i][j] - (k - 1);
            }
        }
    }
    cout << ans << endl;
}