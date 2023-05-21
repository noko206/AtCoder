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

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<int>> field(h, vector<int> (w, 0)); // -1:block, 0:none, 1:light, 2:ok
    REP(i, n){
        int a, b;
        cin >> a >> b;
        --a, --b;
        field[a][b] = 1;
    }
    REP(i, m){
        int c, d;
        cin >> c >> d;
        --c, --d;
        field[c][d] = -1;
    }
    REP(i, h){
        int status = -1;
        REP(j, w){
            switch(field[i][j]){
                case -1:
                    status = -1;
                    break;
                case 0:
                    if(status == 1){
                        status = 1;
                        if(field[i][j] == 0){
                            field[i][j] = 2;
                        }
                    }
                    break;
                case 1:
                    status = 1;
                    break;
            }
        }
    }
    REP(i, h){
        int status = -1;
        for(int j = w - 1; j >= 0; --j){
            switch(field[i][j]){
                case -1:
                    status = -1;
                    break;
                case 0:
                    if(status == 1){
                        status = 1;
                        if(field[i][j] == 0){
                            field[i][j] = 2;
                        }
                    }
                    break;
                case 1:
                    status = 1;
                    break;
            }
        }
    }
    REP(j, w){
        int status = -1;
        REP(i, h){
            switch(field[i][j]){
                case -1:
                    status = -1;
                    break;
                case 0:
                    if(status == 1){
                        status = 1;
                        if(field[i][j] == 0){
                            field[i][j] = 2;
                        }
                    }
                    break;
                case 1:
                    status = 1;
                    break;
            }
        }
    }
    REP(j, w){
        int status = -1;
        for(int i = h - 1; i >= 0; --i){
            switch(field[i][j]){
                case -1:
                    status = -1;
                    break;
                case 0:
                    if(status == 1){
                        status = 1;
                        if(field[i][j] == 0){
                            field[i][j] = 2;
                        }
                    }
                    break;
                case 1:
                    status = 1;
                    break;
            }
        }
    }
    int ans = 0;
    REP(i, h){
        REP(j, w){
            if(field[i][j] >= 1) ++ans;
        }
    }
    cout << ans << endl;
}