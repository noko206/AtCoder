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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    ll ok = 2e9 + 1;
    ll ng = -1;
    auto solve = [a, n, k](ll x){
        ll cnt = 0;
        REP(i, n){
            cnt += max(0LL, a[i] - x);
        }
        return cnt < k;
    };
    while(ok - ng != 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    ll ans = 0;
    auto f = [&](ll l, ll r){
        return (l + r) * (r - l + 1) / 2;
    };
    REP(i, n){
        if(a[i] - ok <= 0) continue;
        ans += f(ok + 1, a[i]);
    }
    ll cnt = 0;
    REP(i, n){
        cnt += max(0LL, a[i] - ok);
    }
    ans += ok * (k - cnt);
    cout << ans << endl;
}