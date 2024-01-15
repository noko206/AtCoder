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
    int from;
    int to;
    int cost;
    bool operator<(const Edge& right) const {
        return cost < right.cost;
    }
};

class UnionFind {
private:
    vector<int> par;
    vector<int> siz;

public:
    UnionFind(int n){
        for (int i = 0; i < n; i++){
            par.push_back(i);
        }
        siz.resize(n, 1);
    }

    int root(int x) {
        if(par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return false;
        }
        if(siz[rx] < siz[ry]){
            swap(rx, ry);
        }
        siz[rx] += siz[ry];
        par[ry] = rx;
        return true;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return siz[root(x)];
    }
};

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<Edge> edge(m), query(q);
    REP(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edge[i].from = a;
        edge[i].to = b;
        edge[i].cost = c;
    }
    REP(i, q){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        query[i].from = u;
        query[i].to = v;
        query[i].cost = w;
    }
    sort(ALL(edge));
    sort(ALL(query));
    int i = 0, j = 0;
    UnionFind uf(n);
    while(i < m && j < q){
        if(edge[i].cost > query[j].cost){
            // cout << query[j].cost << endl;
            if(query[j].from == query[j].to || uf.same(query[j].from, query[j].to)){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
            ++j;
        }
        else{
            // cout << edge[i].cost << endl;
            if(edge[i].from != edge[i].to && !uf.same(edge[i].from, edge[i].to)){
                uf.unite(edge[i].from, edge[i].to);
            }
            ++i;
        }
    }
    REP(_, j, q){
        cout << "No" << endl;
    }
}