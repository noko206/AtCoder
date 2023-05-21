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
const int MOD = 998244353;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

ll dp[2005][2005][5]; // i回目、最後がj、xの出現回数の偶奇
using Graph = vector<vector<int>>;
struct Data{
    int cnt;
    int v;
    int x_odd;
};

int main(){
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    --s, --t, --x;
    Graph G(n);
    REP(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<Data> q;
    Data d;
    d.cnt = 0;
    d.v = s;
    d.x_odd = 0;
    q.push(d);
    dp[0][s][0] = 1;
    while(!q.empty()){
        d = q.front();
        q.pop();
        int cnt = d.cnt;
        if(cnt == k) break;
        int v = d.v;
        // cout << v << endl;
        int x_odd = d.x_odd;
        for(int u : G[v]){
            int tmp = x_odd;
            if(u == x) tmp = (tmp + 1) % 2;
            if(dp[cnt + 1][u][tmp] == 0LL){
                dp[cnt + 1][u][tmp] += dp[cnt][v][x_odd];
                dp[cnt + 1][u][tmp] %= MOD;
                Data e;
                e.cnt = cnt + 1;
                e.v = u;
                e.x_odd = tmp;
                q.push(e);
            }
            else{
                dp[cnt + 1][u][tmp] += dp[cnt][v][x_odd];
                dp[cnt + 1][u][tmp] %= MOD;
                // Data e;
                // e.cnt = cnt + 1;
                // e.v = u;
                // e.x_odd = tmp;
                // q.push(e);
            }
        }
    }
    cout << dp[k][t][0] << endl;
    // REP(i, k + 1){
    //     REP(j, n){
    //         cout << dp[i][j][0] << ' ';
    //     }
    //     cout << endl;
    // }
}