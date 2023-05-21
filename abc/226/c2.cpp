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

vector<int> t(200200), k(200200);
vector<vector<int>> a(200200);
set<int> s;
vector<bool> ok(200200, false);

void dfs(int x){
    if(ok[x]){
        return;
    }
    for(int v : a[x]){
        if(ok[v]) continue;
        dfs(v);
    }
    ok[x] = true;
    s.insert(x);
}

int main(){
    int n;
    cin >> n;
    REP(i, n){
        cin >> t[i] >> k[i];
        a[i].resize(k[i]);
        REP(j, k[i]){
            cin >> a[i][j];
            --a[i][j];
        }
        // sort(ALL(a[i]));
    }
    dfs(n - 1);
    ll ans = 0;
    for(auto it = s.begin(); it != s.end(); ++it){
        ans += t[*it];
    }
    cout << ans << endl;
}