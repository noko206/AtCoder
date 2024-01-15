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
const int MOD = 998244353;
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
    ll n;
    cin >> n;
    if(1 <= n && n <= 9){
        cout << n * (n + 1) / 2 << endl;
        return 0;
    }
    ll m = n / 10;
    ll cnt = 1;
    ll ans = 45;
    while(!(1 <= m && m <= 9)){
        ll k = (ll)pow(10, cnt + 1) - (ll)pow(10, cnt);
        // cout << k << endl;
        k %= MOD;
        ll tmp = 1;
        tmp *= k;
        tmp %= MOD;
        tmp *= (k + 1);
        tmp %= MOD;
        tmp *= mod_inv(2, MOD);
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
        m /= 10;
        ++cnt;
        // cout << ans << endl;
    }
    ll k = n - (ll)pow(10, cnt) + 1;
    k %= MOD;
    // cout << k << endl;
    ll tmp = 1;
    tmp *= k;
    tmp %= MOD;
    tmp *= (k + 1);
    tmp %= MOD;
    tmp *= mod_inv(2, MOD);
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
    cout << ans << endl;
}