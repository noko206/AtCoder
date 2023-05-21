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
    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n);
    ll x_min, y_min, x_max, y_max;
    x_min = y_min = LLINF;
    x_max = y_max = -LLINF;
    REP(i, n){
        cin >> x[i] >> y[i];
        ll tmp1 = x[i] + y[i];
        ll tmp2 = y[i] - x[i];
        x[i] = tmp1;
        y[i] = tmp2;
        chmin(x_min, x[i]);
        chmin(y_min, y[i]);
        chmax(x_max, x[i]);
        chmax(y_max, y[i]);
    }
    vector<ll> ans(q);
    REP(i, q){
        int t;
        cin >> t;
        --t;
        ll d1 = abs(x[t] - x_min);
        ll d2 = abs(x[t] - x_max);
        ll d3 = abs(y[t] - y_min);
        ll d4 = abs(y[t] - y_max);
        ans[i] = max({d1, d2, d3, d4});
    }
    REP(i, q){
        cout << ans[i] << endl;
    }
}