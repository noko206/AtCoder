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

struct Edge {
    int to;
};

using Graph = vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.top();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to);
            }
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    Graph G(n);
    REP(i, m){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        Edge e;
        e.to = b[i];
        G[a[i]].push_back(e);
    }
    vector<int> res = topo_sort(G);
    if(res.size() != n){
        cout << -1 << endl;
    }
    else{
        for(int v : res){
            cout << v + 1 << ' ';
        }
        cout << endl;
    }   
}