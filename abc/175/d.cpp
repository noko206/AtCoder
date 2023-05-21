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
    vector<int> p(n), c(n);
    REP(i, n){
        cin >> p[i];
        --p[i];
    }
    REP(i, n){
        cin >> c[i];
    }
    ll ans = -LLINF;
    REP(i, n){
        int x = i;
        vector<int> cycle;
        ll total = 0;
        while(true){
            x = p[x];
            cycle.push_back(c[x]);
            total += c[x];
            if(x == i){
                break;
            }
        }
        int l = cycle.size();
        ll t = 0;
        REP(j, l){
            if(j >= k){
                break;
            }
            t += cycle[j];
            ll now = t;
            if(total > 0){
                ll num = (k - (j + 1)) / l;
                now += total * num;
            }
            chmax(ans, now);
        }
    }
    cout << ans << endl;
}