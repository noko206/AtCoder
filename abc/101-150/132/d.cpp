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

ll mod_conb(ll a, ll b, ll m) {
    ll ans = 1;
    for(int i = 0; i < b; ++i){
        ans *= a - i;
        ans %= m;
    }
    for(int i = 0; i < b; ++i){
        ans *= mod_inv(i + 1, m);
        ans %= m;
    }
    return ans;
}

ll mod_cnt_multi(ll a, ll b, ll m){
    if(a == 0 && b == 0) return 1;
    if(a <= 0 || b < 0) return 0;
    return mod_conb(a + b - 1, b, m);
}

int main(){
    int n, k;
    cin >> n >> k;
    int B = k;
    int R = n - k;
    REP(i, 1, B + 1){
        int r = R - (i - 1);
        int b = B - i;
        ll c1 = f(i, b);
        ll c2 = f(i + 1, r);
        cout << (c1 * c2) % MOD << endl;
    }
}