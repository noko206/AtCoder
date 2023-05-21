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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n, 0);
    ll tot = 0;
    REP(i, n){
        cin >> a[i];
        if(i > 0){
            b[i] = a[i] - a[i - 1];
            tot += abs(b[i]);
        }
    }
    vector<ll> ans(q);
    REP(i, q){
        int l, r, v;
        cin >> l >> r >> v;
        --l, --r;
        if(l > 0){
            tot -= abs(b[l]);
            b[l] += v;
            tot += abs(b[l]);
        }
        if(r + 1 < n){
            tot -= abs(b[r + 1]);
            b[r + 1] -= v;
            tot += abs(b[r + 1]);
        }
        ans[i] = tot;
    }
    REP(i, q){
        cout << ans[i] << endl;
    }
}