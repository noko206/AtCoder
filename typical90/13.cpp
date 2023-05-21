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

struct Edge {
    long long to;
    long long cost;
};

using Graph = vector<vector<Edge>>;
using P = pair<long, int>;

void dijkstra(const Graph &G, int s, vector<ll> &dis) {
    int N = G.size();
    dis.resize(N, LLINF);
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
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
        --a, --b;
        Edge e1, e2;
        e1.to = b, e2.to = a;
        e1.cost = e2.cost = c;
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    vector<ll> dis, disn;
    dijkstra(G, 0, dis);
    dijkstra(G, n - 1, disn);
    REP(i, 0, n){
        cout << dis[i] + disn[i] << endl;
    }
}