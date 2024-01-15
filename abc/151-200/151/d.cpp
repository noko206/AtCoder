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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h){
        cin >> s[i];
    }
    int ans = 0;
    REP(sh, h) REP(sw, w) {
        if(s[sh][sw] == '#') continue;
        queue<pair<int, int>> q;
        q.emplace(sh, sw);
        vector<vector<int>> dist(h, vector<int>(w, INF));
        dist[sh][sw] = 0;
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            int y = p.first;
            int x = p.second;
            REP(i, 4){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(s[ny][nx] == '#') continue;
                if(dist[ny][nx] != INF) continue;
                dist[ny][nx] = dist[y][x] + 1;
                chmax(ans, dist[ny][nx]);
                q.emplace(ny, nx);
            }
        }
    }
    cout << ans << endl;
}