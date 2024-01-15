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
    vector<int> a(n);
    vector<vector<int>> x(n), y(n);
    REP(i, n){
        cin >> a[i];
        x[i].resize(a[i]);
        y[i].resize(a[i]);
        REP(j, a[i]){
            cin >> x[i][j] >> y[i][j];
            --x[i][j];
        }
    }
    int ans = 0;
    REP(bit, 1 << n){
        vector<bool> is_honest(n, false);
        REP(i, n){
            if(bit & (1 << i)){
                is_honest[i] = true;
            }
        }
        bool is_ok = true;
        REP(i, n){
            if(!is_honest[i]) continue;
            REP(j, a[i]){
                if(y[i][j] == 0 && is_honest[x[i][j]]){
                    is_ok = false;
                }
                if(y[i][j] == 1 && !is_honest[x[i][j]]){
                    is_ok = false;
                }
            }
        }
        if(is_ok) chmax(ans, __builtin_popcount(bit));
    }
    cout << ans << endl;
}