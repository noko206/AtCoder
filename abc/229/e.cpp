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

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    Graph G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans(n);
    ans[n - 1] = 0;
    int cnt = 0;
    for(int i = n - 1; i > 0; --i){
        ++cnt;
        // if(i == n - 1){
        //     ans[i] = 0;
        //     continue;
        // }
        // if(i == n - 2){
        //     ans[i] = 1;
        //     continue;
        // }
        for(int v : G[i]){
            if(v < i) continue;
            // if(i == 2){
            //     cout << v << endl;
            // }
            if(!uf.same(i, v)){
                --cnt;
            }
            uf.unite(i, v);
        }
        ans[i - 1] = cnt;
    }

    // REP(i, m){
    //     if(!uf.same(a[i], b[i])){
    //         --cnt;
    //     }
    //     uf.unite(a[i], b[i]);
    //     ans[i] = cnt;
    // }
    // reverse(ALL(ans));
    REP(i, n){
        cout << ans[i] << endl;
    }
}