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

int n;
vector<int> h, s;

bool solve(ll x){
    vector<ll> t(n);
    REP(i, n){
        if(x < h[i]){
            return false;
        }
        t[i] = (x - h[i]) / s[i];
    }
    sort(ALL(t));
    REP(i, n){
        if(i > t[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    h.resize(n);
    s.resize(n);
    REP(i, n){
        cin >> h[i] >> s[i];
    }
    ll ok = LLINF;
    ll ng = 0;
    while(ok - ng != 1){
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