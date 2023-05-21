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
    vector<ll> tot(n, 0);
    map<ll, int> cnt;
    REP(i, n){
        cin >> a[i];
        tot[i] += a[i];
        if(i != 0){
            tot[i] += tot[i - 1];
        }
        ++cnt[tot[i]];
        // cout << tot[i] << endl;
    }
    ll ans = 0;
    REP(i, n){
        --cnt[tot[i]];
        if(tot[i] == k){
            ++ans;
        }
        if(cnt.find(tot[i] + k) != cnt.end()){
            // cout << i << endl;
            ans += cnt[tot[i] + k];
        }
    }
    cout << ans << endl;
}