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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int h, w, k;

void dfs(vector<string> &c, int y, int x, int cnt, vector<vector<int>> &seen){
    if(seen[y][x] == 2){
        if(cnt >= 3){
            chmax(k, cnt);
        }
        return;
    }
    if(cnt == 0){
        seen[y][x] = 2;
    }
    else{
        seen[y][x] = 1;
    }
    REP(i, 4){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx < 0 || nx >= w || ny < 0 || ny >= h){
            continue;
        }
        if(c[ny][nx] == '#'){
            continue;
        }
        if(seen[ny][nx] == 1){
            continue;
        }
        dfs(c, ny, nx, cnt + 1, seen);
    }
}

int main(){
    cin >> h >> w;
    vector<string> c(h);
    REP(i, h){
        cin >> c[i];
    }
    int ans = -1;
    REP(i, h){
        REP(j, w){
            k = -1;
            vector<vector<int>> seen(h, vector<int>(w, 0));
            dfs(c, i, j, 0, seen);
            chmax(ans, k);
        }
    }
    cout << ans << endl;
}