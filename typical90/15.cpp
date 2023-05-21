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

ll mod_inv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    int n;
    cin >> n;
    vector<ll> f(n + 1);
    f[0] = 1;
    REP(i, 1, n + 1){
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    vector<ll> fi(n + 1);
    REP(i, n + 1){
        fi[i] = mod_inv(f[i], MOD);
    }
    vector<ll> ans(n);
    for(ll k = 1; k <= n; ++k){
        ll cnt = 0;
        for(ll a = 1; a <= n; ++a){
            if(n - (k - 1) * (a - 1) < a) break;
            ll tmp = f[n - (k - 1) * (a - 1)];
            tmp %= MOD;
            tmp *= fi[n - (k - 1) * (a - 1) - a];
            tmp %= MOD;
            tmp *= fi[a];
            tmp %= MOD;
            cnt += tmp;
            cnt %= MOD;
        }
        ans[k - 1] = cnt;
    }
    REP(i, n){
        cout << ans[i] << endl;
    }
}