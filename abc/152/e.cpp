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

const int MAX = 1001001;

ll mod_pow(ll a, ll n, ll p) {
    if(n == 0) return 1;
    return (n == 1)? a: a * mod_pow(a, n - 1, p) % p;
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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    vector<int> sieve(MAX, 0);
    sieve[0] = -1;
    sieve[1] = -1;
    REP(i, 2, MAX){
        if(sieve[i] > 0){
            continue;
        }
        for (int j = i; j < MAX; j += i){
            sieve[j] = i;
        }
    }
    vector<int> prime_factors(MAX, 0);
    REP(i, n){
        map<int, int> mp;
        int v = a[i];
        while(v > 1){
            ++mp[sieve[v]];
            v /= sieve[v];
        }
        for(pair<int, int> p : mp){
            chmax(prime_factors[p.first], p.second);
        }
    }
    ll x = 1;
    REP(i, 2, MAX){
        ll res = mod_pow(i, prime_factors[i], MOD);
        if(res != 1){
            // cout << res << endl;
            x *= res;
            x %= MOD;
        }
    }
    ll ans = 0;
    REP(i, n){
        ans += x * mod_inv((ll)a[i], MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}