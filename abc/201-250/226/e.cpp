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

using Graph = vector<vector<int>>;

vector<bool> seen, finished;
int pos = -1;
stack<int> hist;

int cycle = 0;

void dfs(const Graph &G, int v, int p) {
    seen[v] = true;
    hist.push(v);
    for (auto nv : G[v]) {
        if (nv == p) continue; // 逆流を禁止する

        // 完全終了した頂点はスルー
        if (finished[nv]) continue;

        // サイクルを検出
        if (seen[nv] && !finished[nv]) {
            pos = nv;
            ++cycle;
            // cout << "ok" << endl;
            return;
        }

        // 再帰的に探索
        dfs(G, nv, v);

        // サイクル検出したならば真っ直ぐに抜けていく
        if (pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    UnionFind uf(n);
    REP(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u, v);
    }
    seen.assign(n, false);
    finished.assign(n, false);
    pos = -1;
    ll ans = 1;
    REP(i, n){
        if(seen[i]) continue;
        dfs(G, i, -1);
        set<int> cycle;
        int t = -1;
        while (!hist.empty()) {
            t = hist.top();
            cycle.insert(t);
            // cout << t << endl;
            hist.pop();
            if (t == pos) break;
        }
        // cout << cycle.size() << endl;
        if(cycle.size() <= 2){
            cout << 0 << endl;
            return 0;
        }
        cout << cycle.size() << endl;
        if(t != -1){
            if(uf.size(t) != cycle.size()){
                cout << 0 << endl;
                return 0;
            }
        }
        ans *= 2;
        ans %= MOD;
        if(!hist.empty()){
            hist.pop();
        }
    }
    cout << ans << endl;
    // cout << cycle.size() << endl;
}