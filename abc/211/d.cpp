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

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    vector<int> vs;
    while(q.size()){
        int v = q.front();
        q.pop();
        vs.push_back(v);
        for(int next : G[v]){
            if(dist[next] != INF){
                continue;
            }
            dist[next] = dist[v] + 1;
            q.push(next);
        }
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int v : vs){
        for(int u : G[v]){
            if(dist[u] == dist[v] + 1){
                dp[u] += dp[v];
                dp[u] %= MOD;
            }
        }
    }
    cout << dp[n - 1] << endl;
}