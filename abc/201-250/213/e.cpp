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

using P = pair<int, int>;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h){
        cin >> s[i];
    }
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    deque<P> dq;
    dq.push_front(make_pair(0, 0));
    while(dq.size()){
        P p = dq.front();
        dq.pop_front();
        seen[p.first][p.second] = true;
        REP(i, 4){
            int y = p.first + dy[i];
            int x = p.second + dx[i];
            if(x < 0 || y < 0 || x >= w || y >= h){
                continue;
            }
            if(seen[y][x]){
                continue;
            }
            if(s[y][x] == '#'){
                continue;
            }
            dist[y][x] = dist[p.first][p.second];
            dq.push_front(make_pair(y, x));
        }
        REP(i, -2, 3){
            REP(j, -2, 3){
                int y = p.first + i;
                int x = p.second + j;
                if(x < 0 || y < 0 || x >= w || y >= h){
                    continue;
                }
                if(seen[y][x]){
                    continue;
                }
                if(abs(i) + abs(j) > 3){
                    continue;
                }
                if(dist[y][x] <= dist[p.first][p.second] + 1){
                    continue;
                }
                dist[y][x] = dist[p.first][p.second] + 1;
                dq.push_back(make_pair(y, x));
            }
        }
    }
    cout << dist[h - 1][w - 1] << endl;
}