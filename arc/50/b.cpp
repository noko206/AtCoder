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
    ll r, b;
    int x, y;
    cin >> r >> b >> x >> y;
    auto solve = [r, b, x, y](ll mid){
        ll nr = r - mid;
        ll nb = b - mid;
        if(nr < 0 || nb < 0) return false;
        return mid <= nr / (x - 1) + nb / (y - 1);
    };
    ll ok = 0;
    ll ng = 1e18 + 1;
    while(ng - ok != 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout << ok << endl;
}