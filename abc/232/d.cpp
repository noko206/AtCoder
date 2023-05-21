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

const int dy[] = {0, 1};
const int dx[] = {1, 0};

using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    REP(i, h){
        cin >> c[i];
    }
    int ans = 1;
    queue<P> q;
    q.push({0, 0}); // {y, x}
    vector<vector<int>> cnt(h, vector<int>(w, 0));
    cnt[0][0] = 1;
    while(!q.empty()){
        P p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        REP(i, 2){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= h || nx >= w) continue;
            if(c[ny][nx] == '#') continue;
            if(cnt[ny][nx] != 0) continue;
            cnt[ny][nx] = cnt[y][x] + 1;
            chmax(ans, cnt[ny][nx]);
            q.push({ny, nx});
        }
    }
    cout << ans << endl;
}