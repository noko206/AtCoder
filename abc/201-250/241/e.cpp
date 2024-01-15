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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    map<int, bool> mp;
    ll x = 0;
    while(mp.find(x % n) == mp.end()){
        mp[x % n] = true;
        x += a[x % n];
        --k;
        if(k == 0){
            cout << x << endl;
            return 0;
        }
    }
    map<int, bool> mp2;
    int cnt = 0;
    ll y = x;
    while(mp2.find(y % n) == mp2.end()){
        mp2[y % n] = true;
        y += a[y % n];
        ++cnt;
    }
    x += (y - x) * (k / (ll)cnt);
    k %= cnt;
    REP(i, k){
        x += a[x % n];
    }
    cout << x << endl;
}