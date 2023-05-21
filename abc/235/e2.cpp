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
    bool is_query;
    bool operator<(const Edge &right) const {
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
    vector<Edge> edge(m + q);
    REP(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edge[i].from = a;
        edge[i].to = b;
        edge[i].cost = c;
        edge[i].is_query = false;
    }
    REP(i, m, m + q){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edge[i].from = u;
        edge[i].to = v;
        edge[i].cost = w;
        edge[i].is_query = true;
    }
    sort(ALL(edge));
    UnionFind uf(n);
    REP(i, m + q){
        if(uf.same(edge[i].from, edge[i].to)){
            if(edge[i].is_query){
                cout << "No" << endl;
            }
        }
        else{
            if(edge[i].is_query){
                cout << "Yes" << endl;
            }
            else{
                uf.unite(edge[i].from, edge[i].to);
            }
        }
    }
}