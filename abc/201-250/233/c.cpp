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

ll n;
ll x, ans;
vector<ll> l;
vector<vector<ll>> a;

void dfs(int k, ll tot){
    if(k == n){
        if(tot == x){
            ++ans;
        }
        return;
    }
    for(ll v : a[k]){
        if(tot <= x / v){
            dfs(k + 1, tot * v);
        }
    }
}

int main(){
    cin >> n >> x;
    l.resize(n);
    a.resize(n);
    REP(i, n){
        cin >> l[i];
        a[i].resize(l[i]);
        REP(j, l[i]){
            cin >> a[i][j];
        }
    }
    ans = 0;
    dfs(0, 1);
    cout << ans << endl;
}