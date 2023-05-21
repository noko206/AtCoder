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

struct Edge{
    int to;
    int cost;
    int time;
};

using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    --x, --y;
    Graph G(n);
    REP(i, m){
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        --a, --b;
        G[a].push_back({b, t, k});
        G[b].push_back({a, t, k});
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, x);
    vector<ll> dist(n, LLINF);
    dist[x] = 0;
    vector<bool> visited(n, false);
    while(!pq.empty()){
        P v = pq.top();
        pq.pop();
        // if(v.first == y){
        //     cout << "ok" << endl;
        //     break;
        // }
        if(visited[v.second]){
            continue;
        }
        visited[v.second] = true;
        for(Edge next : G[v.second]){
            // ll change = -1;
            // if(v.first <= next.time){
            //     change = next.time - v.first;
            // }
            // else{
            //     change = v.first % next.time;
            // }
            // if(v.first == 0){
            //     change = 0;
            // }

            // ll ok = INF / next.time;
            // ll ng = 0;
            // while(ok - ng != 1){
            //     ll mid = (ok + ng) / 2;
            //     if(v.first <= next.time * mid){
            //         ok = mid;
            //     }
            //     else{
            //         ng = mid;
            //     }
            // }
            // ll change = 0;
            // if(v.first != 0){
            //     change = next.time * ok - v.first;
            // }

            // if(dist[next.to] != LLINF){
            //     continue;
            // }

            ll cost = (v.first + next.time - 1) / next.time * next.time + next.cost;

            // ll cost = v.first + change + next.cost;
            if(chmin(dist[next.to], cost)){
                pq.emplace(cost, next.to);
            }
        }
    }
    if(dist[y] == LLINF){
        cout << -1 << endl;
    }
    else{
        cout << dist[y] << endl;
    }
}