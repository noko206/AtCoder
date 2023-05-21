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
    int c;
};

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
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    Pos p;
    p.y = rs;
    p.x = cs;
    p.d = -1;
    p.c = 0;
    dq.push_front(p);
    int ans = -1;
    while(!dq.empty()){
        Pos v = dq.front();
        dq.pop_front();
        seen[v.y][v.x] = true;
        if(v.y == rt && v.x == ct){
            ans = v.c;
            break;
        }
        REP(i, 4){
            Pos u;
            u.y = v.y + dy[i];
            u.x = v.x + dx[i];
            u.d = i;
            u.c = v.c;
            if(u.y < 0 || u.x < 0 || u.y >= h || u.x >= w){
                continue;
            }
            if(seen[u.y][u.x]){
                continue;
            }
            if(s[u.y][u.x] == '#'){
                continue;
            }
            if(v.d == -1 || v.d == u.d){
                dq.push_front(u);
            }
            else{
                ++u.c;
                dq.push_back(u);
            }
        }
    }
    cout << ans << endl;
}