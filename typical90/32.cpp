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
    vector<vector<int>> a(n, vector<int>(n));
    REP(i, n){
        REP(j, n){
            cin >> a[i][j];
        }
    }
    int m;
    cin >> m;
    vector<vector<int>> f(n, vector<int>(n, false));
    REP(i, m){
        int x, y;
        cin >> x >> y;
        --x, --y;
        f[x][y] = true;
        f[y][x] = true;
    }
    vector<int> np(n);
    REP(i, n){
        np[i] = i;
    }
    int ans = INF;
    do{
        int tmp = 0;
        REP(i, n){
            tmp += a[np[i]][i];
            if(i == 0){
                continue;
            }
            if(f[np[i]][np[i - 1]]){
                tmp = -1;
                break;
            }
        }
        if(tmp != -1){
            chmin(ans, tmp);
        }
    } while (next_permutation(ALL(np)));
    if(ans != INF){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}