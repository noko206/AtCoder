#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;

void dijkstra(const Graph &G, int s, vector<long long> &dis, int k) {
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                if(e.to > k){
                    continue;
                }
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    REP(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        Edge edge;
        edge.to = b - 1;
        edge.cost = c;
        G[a - 1].push_back(edge);
    }
    ll ans = 0;
    REP(k, n){
        Graph G_tmp = G;
        REP(i, n){
            vector<ll> dis(n, LLINF);
            dis[i] = 0;
            dijkstra(G_tmp, i, dis, k);
            for(ll d : dis){
                if(d != LLINF){
                    ans += d;
                }
                // cout << d << ' ';
            }
            // cout << endl;
        }
    }
    cout << ans << endl;
}