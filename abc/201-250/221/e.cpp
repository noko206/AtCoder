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

int modPow(long long a, long long n, long long p) {
    if(n == 0){
        return 1;
    }
    return (n == 1)? a: a * modPow(a, n - 1, p) % p;
}

int main(){
    cout << (int)pow(32, 6) << endl;
    return 0;
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    int j = 1;
    ll ans = 0;
    REP(i, n){
        REP(j, i + 1, n){
            if(a[i] > a[j]){
                continue;
            }
            ans += (ll)modPow(2LL, (ll)(j - i - 1), (ll)MOD);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}