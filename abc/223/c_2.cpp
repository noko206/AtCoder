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
    cin >> n;
    vector<ll> a(n), b(n);
    ll b_sum = 0;
    REP(i, n){
        cin >> a[i] >> b[i];
        b_sum += b[i];
    }
    ll sec = 0;
    REP(i, n){
        sec += (b_sum / b[i]) * a[i];
    }
    ll cnt = 0;
    ll ans = 0;
    double _ans = 0.0;
    // cout << ((double)sec / (double)b_sum) / 2.0 << endl;
    REP(i, n){
        cnt += (b_sum / b[i]) * a[i];
        ans += a[i];
        if(2 * cnt == sec){
            break;
        }
        if(sec < 2 * cnt){
            ans -= a[i];
            double _sec = ((double)sec / (double)b_sum) / 2.0;
            double _cnt = (double)cnt / (double)b_sum;
            _ans = (double)b[i] * (_sec - (_cnt - (double)a[i]));
            break;
        }
    }
    _ans += (double)ans;
    printf("%.8f\n", _ans);
}