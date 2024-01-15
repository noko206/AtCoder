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

ll mod_pow(ll a, ll n, ll p) {
    if (n == 0) return 1;
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * mod_pow(a, n - 1, p)) % p;
    ll t = mod_pow(a, n / 2, p);
    return (t * t) % p;
}

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
    int n, m, k;
    cin >> n >> m >> k;
    if(m == 1 && k == n - 1){
        cout << 1 << endl;
        return 0;
    }
    ll ans = 0;
    ll m_tmp = mod_pow(m - 1, n - 1, MOD);
    ll c_tmp = 1;
    REP(i, k + 1){
        if(i > 0){
            m_tmp *= mod_inv(m - 1, MOD);
            m_tmp %= MOD;
            c_tmp *= n - i;
            c_tmp %= MOD;
            c_tmp *= mod_inv(i, MOD);
            c_tmp %= MOD;
        }
        ll ans_tmp = m;
        ans_tmp *= m_tmp;
        ans_tmp %= MOD;
        ans_tmp *= c_tmp;
        ans_tmp %= MOD;
        ans += ans_tmp;
        ans %= MOD;
    }
    cout << ans << endl;
}