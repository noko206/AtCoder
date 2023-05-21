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

ll base8_to_10(ll n){
    ll ans = 0;
    ll keta = 1;
    while(n > 0){
        ans += (n % 10) * keta;
        n /= 10;
        keta *= 8;
    }
    return ans;
}

ll base10_to_9_to_8(ll n){
    string ans = "";
    while(n > 0){
        if(n % 9 == 8){
            ans += "5";
        }
        else{
            ans += (char)((n % 9) + '0');
        }
        n /= 9;
    }
    reverse(ALL(ans));
    return stoll(ans);
}

int main(){
    ll n;
    int k;
    cin >> n >> k;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    REP(i, k){
        n = base8_to_10(n);
        n = base10_to_9_to_8(n);
    }
    cout << n << endl;
}