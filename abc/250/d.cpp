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
    ll n;
    cin >> n;
    vector<bool> sieve(1000005, true);
    sieve[0] = false;
    sieve[1] = false;
    REP(i, 2, 1000005) {
        if (!sieve[i]) continue;
        for (int j = i * 2; j < 1000005; j += i) {
            sieve[j] = false;
        }
    }
    vector<int> prime;
    REP(i, 1000001) {
        if (sieve[i]) {
            prime.push_back(i);
        }
    }
    int m = (int)prime.size();
    ll ans = 0;
    // p[i] < p[j]
    REP(i, m){
        REP(j, i + 1, m) {
            ll p = prime[i];
            ll q = prime[j];
            ll q3 = q * q * q;
            // オーバーフロー判定
            if (q3 >= (LLINF / p)) {
                break;
            }
            ll k = p * q3;
            if (k <= n) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}