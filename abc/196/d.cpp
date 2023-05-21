#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 1LL<<60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int h, w;
bool used[16][16];

ll dfs(int y, int x, int a, int b){
    if(a < 0 || b < 0){
        return 0;
    }
    if(x == w){
        ++y;
        x = 0;
    }
    if(y == h){
        return 1;
    }
    if(used[y][x]){
        return dfs(y, x + 1, a, b);
    }
    ll res = 0;
    used[y][x] = true;
    res += dfs(y, x + 1, a, b - 1);
    if(x < w && !used[y][x + 1]){
        used[y][x + 1] = true;
        res += dfs(y, x + 1, a - 1, b);
        used[y][x + 1] = false;
    }
    if(y < h && !used[y + 1][x]){
        used[y + 1][x] = true;
        res += dfs(y, x + 1, a - 1, b);
        used[y + 1][x] = false;
    }
    used[y][x] = false;
    return res;
}

int main(){
    int a, b;
    cin >> h >> w >> a >> b;
    cout << dfs(0, 0, a, b) << endl;
}