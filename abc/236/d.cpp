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
    int m = n * 2;
    vector<vector<int>> a(m, vector<int>(m));
    REP(i, m - 1){
        REP(j, i + 1, m){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    function<void(vector<bool>, ll)> dfs = [&](vector<bool> used, ll tot) {
        int i = -1;
        REP(k, m){
            if(!used[k]){
                i = k;
                used[i] = true;
                break;
            }
        }
        if(i == -1){
            chmax(ans, tot);
            return;
        }
        REP(j, m){
            if(!used[j]){
                used[j] = true;
                dfs(used, tot ^ a[i][j]);
                used[j] = false;
            }
        }
    };
    vector<bool> used(m, false);
    dfs(used, 0);
    cout << ans << endl;
}