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

const int wy[] = {-1, 1, 1, -1, -2, -2, -2, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2};
const int wx[] = {1, 1, -1, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1};

int main(){
    int h, w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    --ch, --cw, --dh, --dw;
    vector<string> s(h);
    REP(i, h){
        cin >> s[i];
    }
    deque<pair<int, int>> q;
    q.emplace_front(ch, cw);
    vector<vector<int>> cnt(h, vector<int>(w, INF));
    cnt[ch][cw] = 0;
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop_front();
        int y = tmp.first;
        int x = tmp.second;
        REP(i, 4){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w){
                continue;
            }
            if(cnt[ny][nx] <= cnt[y][x]){
                continue;
            }
            if(s[ny][nx] == '#'){
                continue;
            }
            q.emplace_front(ny, nx);
            cnt[ny][nx] = cnt[y][x];
        }
        REP(i, 20){
            int ny = y + wy[i];
            int nx = x + wx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w){
                continue;
            }
            if(cnt[ny][nx] <= cnt[y][x] + 1){
                continue;
            }
            if(s[ny][nx] == '#'){
                continue;
            }
            q.emplace_back(ny, nx);
            cnt[ny][nx] = cnt[y][x] + 1;
        }
    }
    if(cnt[dh][dw] == INF){
        cout << -1 << endl;
    }
    else{
        cout << cnt[dh][dw] << endl;
    }
    // REP(i, h){
    //     REP(j, w){
    //         cout << cnt[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}