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

ll div_ceil(ll a, ll b){
    return (a + b - 1) / b;
}

bool check2(ll x, ll y, ll a, ll b){
    ll w = div_ceil(a, y) + div_ceil(b, y);
    return w <= x;
}

bool check(ll x, ll y, ll a, ll b, ll c){
    ll w = div_ceil(a, y);
    if(w >= x){
        return false;
    }
    x -= w;
    return check2(x, y, b, c) || check2(y, x, b, c);
}

int main(){
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    REP(fi, 2){
        REP(ri, 3){
            if(check(x, y, a, b, c)){
                cout << "Yes" << endl;
                return 0;
            }
            swap(a, b);
            swap(b, c);
        }
        swap(x, y);
    }
    cout << "No" << endl;
}