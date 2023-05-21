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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n);
    REP(i, n){
        cin >> c[i];
        a[i].resize(m);
        REP(j, m){
            cin >> a[i][j];
        }
    }
    int ans = INF;
    REP(i, 1 << n){
        int cost = 0;
        vector<int> cnt(m, 0);
        REP(j, n){
            if(i & (1 << j)){
                cost += c[j];
                REP(k, m){
                    cnt[k] += a[j][k];
                }
            }
        }
        bool is_ok = true;
        REP(j, m){
            if(cnt[j] < x){
                is_ok = false;
            }
        }
        if(is_ok){
            chmin(ans, cost);
        }
    }
    if(ans == INF){
        ans = -1;
    }
    cout << ans << endl;
}