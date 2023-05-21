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
    string s;
    cin >> s;
    vector<ll> rc;
    bool is_maru = (s[0] == 'o') ? true : false;
    ll cnt = 0;
    for(char c : s){
        if((c == 'o' && !is_maru) || (c == 'x' && is_maru)){
            rc.push_back(cnt);
            is_maru = ((int)is_maru + 1) % 2;
            cnt = 0;
        }
        ++cnt;
    }
    rc.push_back(cnt);
    ll ans = 0;
    for(ll v : rc){
        ans += v * (v + 1) / 2;
    }
    cout << n * (n + 1) / 2 - ans << endl;
}