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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1, 0), b(m + 1, 0);
    int tmp;
    REP(i, n){
        cin >> tmp;
        a[i + 1] = tmp + a[i];
    }
    REP(i, m){
        cin >> tmp;
        b[i + 1] = tmp + b[i];
    }
    int ans = 0;
    REP(i, n + 1){
        int ok = -1;
        int ng = m + 1;
        while(ng - ok != 1){
            int mid = (ok + ng) / 2;
            if(a[i] + b[mid] <= (ll)k){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        if(ok == -1){
            continue;
        }
        chmax(ans, i + ok);
    }
    cout << ans << endl;
}