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

// Union-Find
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

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
    int h, w, q;
    cin >> h >> w >> q;
    UnionFind uf(h * w);
    vector<bool> is_red(h * w, false);
    vector<bool> ans;
    REP(i, q){
        int query;
        cin >> query;
        if(query == 1){
            int r, c;
            cin >> r >> c;
            --r, --c;
            int p = r * w + c;
            is_red[p] = true;
            REP(j, 4){
                int y = r + dy[j];
                int x = c + dx[j];
                if(y < 0 || x < 0 || y >= h || x >= w){
                    continue;
                }
                int n = y * w + x;
                if(!is_red[n]){
                    continue;
                }
                uf.unite(p, n);
            }
        }
        else{
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            --ra, --ca, --rb, --cb;
            int a = ra * w + ca;
            int b = rb * w + cb;
            if(!is_red[a] || !is_red[b]){
                ans.push_back(false);
                continue;
            }
            if(!uf.same(a, b)){
                ans.push_back(false);
                continue;
            }
            ans.push_back(true);
        }
    }
    for(bool v : ans){
        if(v){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}