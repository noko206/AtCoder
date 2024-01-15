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
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    if(k == 1){
        ll sum = 0;
        REP(i, n){
            sum += a[i];
        }
        cout << sum << endl;
        return 0;
    }
    sort(ALL(a));
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    REP(i, k - 1){
        pq.push(a[n - i - 1]);
    }
    ll ans = 0;
    ll minus = 0;
    int ng = n - k + 1;
    REP(i, n - k + 1){
        if(i >= ng){
            break;
        }
        ll v = pq.top();
        v -= minus;
        // cout << v << endl;
        pq.pop();
        if(a[i] < v){
            ans += a[i];
            v -= a[i];
            minus += a[i];
            v += minus;
            pq.push(v);
        }
        else if(a[i] == v){
            ans += a[i];
            minus += a[i];
            --ng;
            pq.push(a[ng] + minus);
        }
        else if(a[i] > v){
            // cout << v << endl;
            ans += v;
            minus += v;
            a[i] -= v;
            --ng;
            pq.push(a[ng] + minus);
            --i;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}