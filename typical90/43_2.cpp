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

struct Pos{
    int y;
    int x;
    int d;
};

int dist[1005][1005][5];

int main(){
    int h, w;
    cin >> h >> w;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    --rs, --cs, --rt, --ct;
    vector<string> s(h);
    REP(i, h){
        cin >> s[i];
    }
    deque<Pos> dq;
    dq.push_front({rs, cs, -1});
    REP(i, h){
        REP(j, w){
            REP(k, 4){
                dist[i][j][k] = INF;
            }
        }
    }
    REP(i, 4){
        dist[rs][cs][i] = 0;
    }
    int cnt = 0;
    while(!dq.empty()){
        Pos v = dq.front();
        dq.pop_front();
        REP(i, 4){
            ++cnt;
            int ny = v.y + dy[i];
            int nx = v.x + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(s[ny][nx] == '#') continue;

            if(v.d == i || v.d == -1){
                if(dist[v.y][v.x][i] >= dist[ny][nx][i]) continue;
                dist[ny][nx][i] = dist[v.y][v.x][i];
                dq.push_front({ny, nx, i});
            }
            else{
                if(dist[v.y][v.x][v.d] + 1 >= dist[ny][nx][i]) continue;
                dist[ny][nx][i] = dist[v.y][v.x][v.d] + 1;
                dq.push_back({ny, nx, i});
            }
        }
    }
    int ans = INF;
    REP(i, 4){
        chmin(ans, dist[rt][ct][i]);
    }
    cout << ans << endl;
    // cout << cnt << endl;
}