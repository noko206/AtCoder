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

int h, w;
vector<vector<int>> val(3000, vector<int>(3000, 0));
ll ans = 0;

const int dy[] = {0, 1};
const int dx[] = {1, 0};

void dfs(vector<int> item_num, int y = 0, int x = -1, ll cnt = 0){
    if(y == h - 1 && x == w - 1){
        chmax(ans, cnt);
        return;
    }
    REP(i, 2){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= h || nx >= w){
            continue;
        }
        dfs(item_num, ny, nx, cnt);
        if(val[ny][nx] != 0){
            ++item_num[ny];
            if(item_num[ny] > 3){
                --item_num[ny];
                continue;
            }
            dfs(item_num, ny, nx, cnt + val[ny][nx]);
            --item_num[ny];
        }
    }
}

int main(){
    cin >> h >> w;
    int k;
    cin >> k;
    REP(i, k){
        int r, c, v;
        cin >> r >> c >> v;
        --r, --c;
        val[r][c] = v;
    }
    vector<int> item_num(3000, 0);
    dfs(item_num);
    cout << ans << endl;
}