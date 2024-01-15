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
    set<int> s;
    s.insert(2);
    s.insert(n);
    for(ll i = 1; i * i <= n - 1; ++i){
        if((n - 1) % i == 0){
            s.insert(i);
            s.insert((n - 1) / i);
        }
    }
    for(ll i = 2; i * i <= n; ++i){
        ll m = n;
        while(m % i == 0){
            m /= i;
        }
        if((m - 1) % i == 0){
            s.insert(i);
        }
        m = n;
        while(m % (n / i) == 0){
            m /= (n / i);
        }
        if((m - 1) % (n / i) == 0){
            s.insert(n / i);
        }
    }
    s.erase(1);
    cout << s.size() << endl;
}