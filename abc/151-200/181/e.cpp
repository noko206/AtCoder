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
    int n, m;
    cin >> n >> m;
    vector<int> h(n), w(m);
    REP(i, n){
        cin >> h[i];
    }
    REP(i, m){
        cin >> w[i];
    }
    sort(ALL(h));
    vector<ll> tot(n);
    REP(i, n){
        if(i == 0) tot[0] = h[0];
        else if(i % 2 == 0) tot[i] = tot[i - 1] + h[i];
        else tot[i] = tot[i - 1] - h[i];
    }
    ll ans = LLINF;
    REP(i, m){
        int ok = -1;
        int ng = n;
        while(ng - ok != 1){
            int mid = (ok + ng) / 2;
            if(h[mid] < w[i]){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        // cout << ok << endl;
        if(ok == -1){
            chmin(ans, tot[n - 1] - w[i]);
        }
        else{
            if(ok % 2 == 1){
                w[i] *= -1;
            }
            chmin(ans, tot[n - 1] - tot[ok] * 2 + w[i]);
        }
    }
    cout << ans << endl;
}