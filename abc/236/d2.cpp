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

ll tot = 0;
vector<vector<ll>> a(20, vector<ll>(20, 0));
int n, m;

void dfs(vector<bool> used, ll ans, int cnt){
    if(cnt == n){
        chmax(tot, ans);
        return;
    }
    REP(i, m - 1){
        if(used[i]) continue;
        REP(j, i + 1, m){
            if(used[j]) continue;
            vector<bool> tmp;
            tmp = used;
            tmp[i] = true;
            tmp[j] = true;
            ll tmp2 = 0;
            if(ans == -1){
                tmp2 = a[i][j];
            }
            else{
                tmp2 = ans ^ a[i][j];
            }
            dfs(tmp, tmp2, cnt + 1);
        }
    }
}

int main(){
    cin >> n;
    m = 2 * n;
    REP(i, m - 1){
        REP(j, i + 1, m){
            cin >> a[i][j];
        }
    }
    vector<bool> used(20, false);
    dfs(used, -1, 0);
    cout << tot << endl;
}